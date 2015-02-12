#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

/*
Algorithm:
1. Load input image
2. Thresh by parts
3. Multiply threshed by color scalar to get part of output
4. Add the parts to make whole output
*/

static void neon_asm_convert( Mat* input, Mat* output, int threshVal)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   "# build the three constants:  \n"
		   "mov r4, #28                   \n" 
		   "mov r5, #151                  \n" 
		   "mov r6, #77                   \n"
		   "mov r8, %3                    \n"
		   "vdup.8 d4, r4                 \n"
		   "vdup.8 d5, r5                 \n"
		   "vdup.8 d6, r6                 \n"
		   "vdup.8 d8, r8                 \n"
		   ".loop:                        \n"
		   "# load 8 pixels:              \n"  
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "# do the weight average:      \n"
		   "vmull.u8 q7, d0, d4           \n"
		   "vmlal.u8 q7, d1, d5           \n"
		   "vmlal.u8 q7, d2, d6           \n"
		   "# shift and store:            \n"
		   "vshrn.u16  d7 , q7 , #8       \n"
		   "vand.8 d7, d7, d8             \n"
		   "vst1.8  {d7}, [%0]!           \n"
		   "subs %2, %2, #1               \n" 
		   "bne .loop                     \n" 
		   :
		   : "r"(dest), "r"(src), "r"(numPixels), "r"(threshVal)
		   : "r4", "r5", "r6", "r8"
		   ); 
}

static void tool_recolor( Mat* input, Mat* output, int iColor[3] )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  int cB = iColor[0];
  int cG = iColor[1];
  int cR = iColor[2];
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   "vdup.8   d4, %3               \n"
		   "vdup.8   d5, %4               \n"
		   "vdup.8   d6, %5               \n"
 
		   ".loop1:                       \n"
		   "vld1.8   {d0}, [%1]!          \n"		  
		   "vand.8   d7, d4, d0           \n"
		   "vand.8   d8, d5, d0           \n"
		   "vand.8   d9, d6, d0           \n"
		   "vst3.8  {d7-d9}, [%0]!        \n"
		   "subs %2, %2, #1               \n" 
		   "bne .loop1                    \n" 
		   :
		   : "r"(dest), "r"(src), "r"(numPixels), "r"(cB), "r"(cG), "r"(cR)
		   ); 
}

int main(void)
{
    Mat image  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat thresh (480, 640, CV_8UC1, Scalar(0));
    Mat dest  (480, 640, CV_8UC3, Scalar(255,0,0));
    int colorArray[8][3] = {{0,255,255},{255,255,0},{255,0,255},{20,100,150},
			    {255,255,255},{255,0,0},{0,255,0},{0,0,255} };
    image = imread("../test.jpg", IMREAD_COLOR); 
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    waitKey(0);
    int i = 0;
    for (;;)
      {
	neon_asm_convert( &image , &thresh , pow(2,i) );
	tool_recolor    ( &thresh, &dest   , colorArray[i] );
	imshow( "Display window", dest );
	i++;
	if ( i>7 ) { i = 0; }
	if ( waitKey(50) > 0 ) break;
      }
    return 0;
    
}
