#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

static void neon_asm_convert( Mat* input, Mat* output, int cols )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  uint8_t __restrict * srcn = input->data + cols*3;
  int numPixels  = input->total() - cols; 
  __asm__ volatile(
		   "lsr %3, %3, #3                \n"
		   		   
		   ".loop:                        \n"
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "vld3.8   {d3-d5}, [%2]!       \n"
		   "veor.8    d6 , d3, d0         \n"
		   "veor.8    d7 , d4, d1         \n"
		   "veor.8    d8 , d5, d2         \n"
		   "vst3.8   {d6-d8}, [%0]!       \n"
		   "subs %3, %3, #1               \n"
		   "bne .loop                     \n"
		   :
		   : "r"(dest), "r"(src), "r"(srcn), "r"(numPixels)
		   :
		   ); 
}

static void neon_asm_or( Mat* input1, Mat* input2, Mat* output )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src1 = input1->data;
  uint8_t __restrict * src2 = input2->data;
  int numPixels  = input1->total(); 
  __asm__ volatile(
		   "lsr %3, %3, #3                \n"
		   "mov r5, #128                  \n"
		   "vdup.8    d10, r5             \n"
		   ".loop2:                       \n"
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "vld3.8   {d3-d5}, [%2]!       \n"
		   "vorr.8    d6 , d3, d0         \n"
		   "vorr.8    d7 , d4, d1         \n"
		   "vorr.8    d8 , d5, d2         \n"
		   "vand.8    d6 , d6, d10        \n"
		   "vand.8    d7 , d7, d10        \n"
		   "vand.8    d8 , d8, d10        \n"
		   "vst3.8   {d6-d8}, [%0]!       \n"
		   "subs %3, %3, #1               \n"
		   "bne .loop2                    \n"
		   :
		   : "r"(dest), "r"(src1), "r"(src2), "r"(numPixels)
		   :
		   ); 
}

static void neon_asm_and( Mat* input1, Mat* input2, Mat* output )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src1 = input1->data;
  uint8_t __restrict * src2 = input2->data;
  int numPixels  = input1->total(); 
  __asm__ volatile(
		   "lsr %3, %3, #3                \n"
		   "mov r5, #128                  \n"
		   "vdup.8    d10, r5             \n"
		   		   
		   ".loop3:                       \n"
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "vld3.8   {d3-d5}, [%2]!       \n"
		   "vand.8    d6 , d3, d0         \n"
		   "vand.8    d7 , d4, d1         \n"
		   "vand.8    d8 , d5, d2         \n"
		   "vand.8    d6 , d6, d10        \n"
		   "vand.8    d7 , d7, d10        \n"
		   "vand.8    d8 , d8, d10        \n"
		   "vst3.8   {d6-d8}, [%0]!       \n"
		   "subs %3, %3, #1               \n"
		   "bne .loop3                    \n"
		   :
		   : "r"(dest), "r"(src1), "r"(src2), "r"(numPixels)
		   :
		   ); 
}

int main(void)
{
    Mat image  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat dest1  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat dest2  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat imaget (640, 480, CV_8UC3, Scalar(0,0,0));
    Mat destt  (640, 480, CV_8UC3, Scalar(0,0,0));
    Mat final  (480, 640, CV_8UC3, Scalar(255,0,0));
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1; 
    
    namedWindow( "Display window" , WINDOW_AUTOSIZE );
    namedWindow( "Image window"   , WINDOW_AUTOSIZE );
    for(;;)
      {
	cap >> image;
	neon_asm_convert( &image, &dest1, image.cols );
	imaget = image.t();
	destt  = dest1.t();
	neon_asm_convert( &imaget, &destt, imaget.cols );
	dest2 = destt.t();
	neon_asm_or( &dest1, &dest2, &final );
	imshow( "Display window"  , final ); 
	neon_asm_and( &dest1, &dest2, &final );
	imshow( "Image window"  , final ); 
	if (waitKey(1)>0) break;
      }
    
    return 0;
}
