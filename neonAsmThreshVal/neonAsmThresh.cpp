#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

static void neon_asm_convert( Mat* input, Mat* output, int threshVal )
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   "mov r4, %3                    \n"
		   "vdup.8 d1, r4                 \n"
		   
		   ".loop:                        \n"
		   "vld1.8   {d0}, [%1]!          \n"
		   "vand.8    d2 , d0, d1         \n"
		   "vst1.8   {d2}, [%0]!          \n"
		   "subs %2, %2, #1               \n" // Decrement iteration count
		   "bne .loop                     \n" // Repeat unil iteration count is not zero
		   :
		   : "r"(dest), "r"(src), "r"(numPixels), "r"(threshVal)
		   : "r4"
		   ); 
}

int main(void)
{
    Mat image  (480, 640, CV_8UC1, Scalar(0));
    Mat dest   (480, 640, CV_8UC1, Scalar(0));
    
    image = imread( "../test.jpg", IMREAD_GRAYSCALE ); 
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    waitKey(0);
    for(int i = 2; i < 8; i++)
      {
	neon_asm_convert( &image, &dest, pow(2,i) );
	imshow( "Display window", dest );
	waitKey(500);
      }
    return 0;
    
}
