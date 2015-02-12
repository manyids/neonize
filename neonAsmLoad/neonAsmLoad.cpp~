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
 
static void load_1 (uint8_t * input, uint8_t * output, int lenData)
{
  __asm__ volatile(
		  "lsr %2, %2, #3       \n"
		  
		  ".loop1:              \n"
		  "vld1.8 {d0}, [%1]!   \n"
		  "vst1.8 {d0}, [%0]!   \n"
		  "subs %2, %2, #1      \n"
		  "bne .loop1           \n"
		  : 
		  : "r"(output), "r"(input), "r"(lenData)
		  );
}

static void load_2 (uint8_t * input, uint8_t * output, int lenData)
{
  __asm__ volatile(
		  "lsr %2, %2, #3              \n"
		  "mov r1, #8                  \n"
		  ".loop1:                     \n"
		  "vld4.8 {d0-d3}, [%1], r1    \n"
		  "vst4.8 [%0], {d0-d3}, r1    \n"
		  "subs %2, %2, #1             \n"
		  "bne .loop1                  \n"
		  : 
		  : "r"(output), "r"(input), "r"(lenData)
		  );
}
 
int main () 
{
  int lenData = 64;
  uint8_t in_data[]    = { 1, 2, 3, 4, 5, 6, 7, 8,
			   9, 10, 11, 12, 13, 14, 15, 16,
			   17, 18, 19, 20, 21, 22, 23, 24,
			   25, 26, 27, 28, 29, 30, 31, 32,
			   33, 34, 35, 36, 37, 38, 39, 40,
			   41, 42, 43 ,44, 45, 46, 47, 48, 
			   49, 50, 51, 52, 53, 54, 55, 56, 
			   57, 58, 59, 60, 61, 62, 63, 64 };
  uint8_t out_data[lenData];
  
  load_1( &in_data[0], &out_data[0], lenData);

  for(int i = 0; i < lenData; i++) 
    { 
      cout << int(in_data[i]) << " ; "  << int(out_data[i]) << endl; 
    }
  return 0;
}
