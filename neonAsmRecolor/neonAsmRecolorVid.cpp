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
1. Load input image (using only blue channel for demo)
2. Thresh by parts (using bitwise and)
3. Multiply threshed by color scalar to get part of output
4. Add the parts to make whole output
*/

static void neon_asm_convert( Mat* input, Mat* output, int threshVal, int iColor[3] )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  int cB = iColor[0];
  int cG = iColor[1];
  int cR = iColor[2];
  __asm__ volatile( 
		   "lsr %2, %2, #3                \n"
		   
		   "vdup.8 d8,  %3                \n"
		   "vdup.8 d10, %4                \n"
		   "vdup.8 d11, %5                \n"
		   "vdup.8 d12, %6                \n"

		   ".loop:                        \n"
		   "pld  [%1, #128]               \n"
		   "pldw [%0, #128]               \n"
		   "vld1.8   {d0}, [%1]!          \n"
		   "add      %1, %1, #2           \n"
		   "vand.8   d7, d0, d8           \n"

		   "vand.8   d13, d10, d7         \n"
		   "vand.8   d14, d11, d7         \n"
		   "vand.8   d15, d12, d7         \n"

		   "vst3.8  {d13-d15}, [%0]!      \n"
		   "subs %2, %2, #1               \n" 
		   "bne .loop                     \n" 
		   :
		   : "r"(dest), "r"(src), "r"(numPixels), "r"(threshVal), "r"(cB), "r"(cG), "r"(cR)
		   ); 
}

int main(void)
{

  VideoCapture cap(0);
  if(!cap.isOpened()) return -1; 

  Mat image (480, 640, CV_8UC3, Scalar(  0,0,0));
  Mat dest  (480, 640, CV_8UC3, Scalar(255,0,0));
  static const int colorArray[8][3] = {{0,255,255},{255,255,0},{255,0,255},{20,100,150},
			    {255,255,255},{255,0,0},{0,255,0},{0,0,255} };
    
  namedWindow( "Image window", WINDOW_AUTOSIZE );
  cap >> image;

  for (;;)
    {
      for (int i = 0; i<8; i++)
	{ 
	  cap >> image;
	  neon_asm_convert( &image , &dest , pow(2,i) , colorArray[i] );
	  imshow( "Image window", dest );
	  if ( waitKey(10) > 0 ) goto outside;
	}
    }
  outside :
  return 0;
}
