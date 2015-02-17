#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include "arm_neon.h"

using namespace cv;
using namespace std;
 
static void neon_asm_thresh ( Mat * input, Mat* output, int* minT, int* maxT)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total();

  int minTb = *minT++; int maxTb = *maxT++;
  int minTg = *minT++; int maxTg = *maxT++;
  int minTr = *minT  ; int maxTr = *maxT  ;

  __asm__ volatile(
		  "lsr %2, %2, #3       \n"
		  "vdup.8 d4, %3        \n"
		  "vdup.8 d5, %4        \n"
		  "vdup.8 d6, %5        \n"
		  "vdup.8 d7, %6        \n"
		  "vdup.8 d8, %7        \n"
		  "vdup.8 d9, %8        \n"
		  
		  ".loop1:                 \n"
		  "vld3.8 {d0-d2}, [%1]!   \n"
		  "vcge.u8 d10 , d0, d4    \n"
		  "vcge.u8 d11 , d5, d0    \n"
		  "vand.8  d0  , d11, d10  \n"
		  "vcge.u8 d10 , d1, d6    \n"
		  "vcge.u8 d11 , d7, d1    \n"
		  "vand.8  d1  , d11, d10  \n"
		  "vcge.u8 d10 , d2, d8    \n"
		  "vcge.u8 d11 , d9, d2    \n"
		  "vand.8  d2  , d11, d10  \n"
		  "vand.8  d0  , d0 , d1   \n"
		  "vand.8  d0  , d0 , d2   \n"
		  "vst1.8 {d0}, [%0]!      \n"
		  "subs %2, %2, #1         \n"
		  "bne .loop1              \n"
		  : 
		  : "r"(dest), "r"(src), "r"(numPixels), "r"(minTb), "r"(maxTb), "r"(minTg), "r"(maxTg), "r"(minTr), "r"(maxTr)
		  );
}
 
int main () 
{
  Mat image  (480, 640, CV_8UC3, Scalar(0,0,0));
  Mat dest   (480, 640, CV_8UC1, Scalar(0));
  int minT[3] = {0,60,0};
  int maxT[3] = {70,255,255};
  
  VideoCapture cap(0);
  if(!cap.isOpened()) return -1; 
  cap >> image;
   
  namedWindow( "Display window" , WINDOW_AUTOSIZE );
  imshow( "Display window", image );
  waitKey(500);
  for (;;)
    {
      cap >> image;
      //cvtColor(image,image,CV_RGB2HSV);
      neon_asm_thresh( &image, &dest, &minT[0], &maxT[0] );
      imshow( "Display window", dest );
      if (waitKey(1)>0) break;
    }
  return 0;
}
