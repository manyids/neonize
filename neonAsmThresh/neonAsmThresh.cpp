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
 
static void neon_asm_thresh ( Mat * input, Mat* output, int minT, int maxT)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		  "lsr %2, %2, #3       \n"
		  "vdup.8 d4, %3        \n"
		  "vdup.8 d5, %4        \n"
		  
		  ".loop1:              \n"
		  "vld1.8 {d0}, [%1]!   \n"
		  "vcge.u8  d2 , d0, d4 \n"
		  "vcge.u8  d3 , d5, d0 \n"
		  "vand.8  d1 , d2, d3  \n"
		  "vst1.8 {d1}, [%0]!   \n"
		  "subs %2, %2, #1      \n"
		  "bne .loop1           \n"
		  : 
		  : "r"(dest), "r"(src), "r"(numPixels), "r"(minT), "r"(maxT)
		  );
}
 
int main () 
{
   Mat image  (480, 640, CV_8UC1, Scalar(0));
   Mat dest   (480, 640, CV_8UC1, Scalar(0));
   int minT = 0;
   int maxT = 255;

   image = imread("../test.jpg", IMREAD_GRAYSCALE);    
   namedWindow( "Display window" , WINDOW_AUTOSIZE );
   imshow( "Display window", image );
   waitKey(0);
   
   neon_asm_thresh( &image, &dest, minT, maxT );
   imshow( "Display window", dest );
   waitKey(0);
   return 0;
}
