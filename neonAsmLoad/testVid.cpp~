#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include </home/odroid/CV/b4Sight/Tools/testVid/funcs.hpp>

using namespace cv;
using namespace std;

int main(void)
{
 
    VideoCapture cap(0); 
    if(!cap.isOpened()) return -1; 
    
    Mat image  (480, 640, CV_8UC3, Scalar(0,0,0));
    Mat dest   (480, 640, CV_8UC1, Scalar(0));
    Mat thresh (480, 640, CV_8UC1, Scalar(0));

    namedWindow( "Thresh window", WINDOW_AUTOSIZE );
    int i = 0;
    uint8_t * pdest;
    uint8_t * psrc;
    for(;;)
      {	
	cap >> image;
	psrc  = image.data;
	pdest = dest.data;
	reference_thresh (pdest, psrc, pow(2,i));
	imshow( "Thresh window", dest );
	int keyP;
	keyP = waitKey(60);
	i++;
	if(i==8) i=0;
	if(keyP==27) break;
      }
    return 0;
    
}
