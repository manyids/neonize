#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

static void neon_asm_convert( Mat* input, Mat* output, int threshVal)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   
		   "mov r4, #28                   \n" 
		   "mov r5, #151                  \n" 
		   "mov r6, #77                   \n"
		   "mov r8, %3                    \n"
		   "vdup.8 d4, r4                 \n"
		   "vdup.8 d5, r5                 \n"
		   "vdup.8 d6, r6                 \n"
		   "vdup.8 d8, r8                 \n"

		   ".loop:                        \n"		  
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "vmull.u8 q7, d0, d4           \n"
		   "vmlal.u8 q7, d1, d5           \n"
		   "vmlal.u8 q7, d2, d6           \n"
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

int main(void)
{
    Mat image  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat dest   (480, 640, CV_8UC1, Scalar(0));
    
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1; 
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    int i = 0;
    for(;;)
      {
	cap >> image;
	neon_asm_convert( &image, &dest, pow(2,i) );
	imshow( "Display window", dest );
	i++;
	if (i>7) {i = 0;} 
	if (waitKey(10)>0) break;
      }
    
    return 0;
}
