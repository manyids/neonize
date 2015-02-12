#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "arm_neon.h"

using namespace cv;
using namespace std;

static void neon_asm_convert( Mat* input, Mat* output)
{
  uint8_t __restrict * dest = output->data;
  uint8_t __restrict * src  = input->data;
  int numPixels  = input->total(); 
  __asm__ volatile(
		   "lsr %2, %2, #3                \n"
		   "# build the three constants:  \n"
		   "mov r4, #28                   \n" // Blue channel multiplier
		   "mov r5, #151                  \n" // Green channel multiplier
		   "mov r6, #77                   \n" // Red channel multiplier
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
    
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1; 
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    
    for(;;)
      {
	cap >> image;
	neon_asm_convert( &image, &dest );
	imshow( "Display window", dest );

	if (waitKey(1)>0) break;
      }
    
    return 0;
}
