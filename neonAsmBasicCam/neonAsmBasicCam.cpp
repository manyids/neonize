#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include "arm_neon.h"

using namespace cv;
using namespace std;
 
static void neon_basic ( Mat* input, Mat* output )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		  "lsr %2, %2, #3          \n"
		  
		  ".loop1:                 \n"
		  "vld3.8 {d0-d2}, [%1]!   \n"
		  "vst3.8 {d0-d2}, [%0]!   \n"
		  "subs %2, %2, #1         \n"
		  "bne .loop1              \n"
		  : 
		  : "r"(dest), "r"(src), "r"(numPixels)
		  );
}

int main () 
{
  VideoCapture cap(0);
  if(!cap.isOpened()) return -1; 

  Mat image (480, 640, CV_8UC3, Scalar(  0,0,0));
  Mat dest  (480, 640, CV_8UC3, Scalar(255,0,0));

  namedWindow( "Image window", WINDOW_AUTOSIZE );
  for (;;)
    {
      cap >> image;
      neon_basic( &image, &dest );
      imshow( "Image window", dest );
      if ( waitKey(10) > 0 ) goto outside;
    }
  outside :
  return 0;
}
