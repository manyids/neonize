#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

static void convert_neon8px_int(const Mat* input, Mat* output)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total();
  
  register int n = numPixels / 8;
  printf("No of Pixels = %d ; n = %d\n ",numPixels,n);
  uint8x8x3_t rgb;
  uint8x8_t rfac = vdup_n_u8 (77);
  uint8x8_t gfac = vdup_n_u8 (151);
  uint8x8_t bfac = vdup_n_u8 (28);
  uint16x8_t  temp;
  uint8x8_t result;
  
  for (register int i = 0; i < n; i++ )
    {
      rgb  = vld3_u8 (src);
            
      temp = vmull_u8 (rgb.val[0],      bfac);
      temp = vmlal_u8 (temp,rgb.val[1], gfac);
      temp = vmlal_u8 (temp,rgb.val[2], rfac);
      
      result = vshrn_n_u16 (temp, 8);
      vst1_u8 (dest, result);
      
      src  += 8*3;
      dest += 8;
    }
}

static void neon_asm_convert( Mat* input, Mat* output)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   "# build the three constants:  \n"
		   "mov r4, #255                  \n" // Blue channel multiplier
		   "mov r5, #255                  \n" // Green channel multiplier
		   "mov r6, #255                  \n" // Red channel multiplier
		   "vdup.8 d4, r4                 \n"
		   "vdup.8 d5, r5                 \n"
		   "vdup.8 d6, r6                 \n"
		   
		   ".loop:                        \n"
		   "# load 8 pixels:              \n"  //RGBR
		   "vld3.8   {d0-d2}, [%1]!       \n"
		   "# do the weight average:      \n"
		   "vmull.u8 q7, d0, d4           \n"
		   "vmlal.u8 q7, d1, d5           \n"
		   "vmlal.u8 q7, d2, d6           \n"
		   "# shift and store:            \n"
		   "vshrn.u16  d7 , q7 , #8       \n" // Divide q3 by 256 and store in the d7
		   "vst1.8  {d7}, [%0]!           \n"
		   "subs %2, %2, #1               \n" // Decrement iteration count
		   "bne .loop                     \n" // Repeat unil iteration count is not zero
		   :
		   : "r"(dest), "r"(src), "r"(numPixels)
		   : "r4", "r5", "r6"
		   ); 
}

int main(void)
{
    Mat image  (480, 640, CV_8UC3, Scalar(255,0,0));
    Mat dest   (480, 640, CV_8UC1, Scalar(0));
    
    image = imread("../test.jpg", IMREAD_COLOR); 
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    waitKey(0);
    neon_asm_convert( &image, &dest );
    imshow( "Display window", dest );

    waitKey(0);
    return 0;
    
}
