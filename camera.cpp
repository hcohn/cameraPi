#include <iostream>
#include </home/pi/opencv-3.0.0/modules/imgproc/include/opencv2/imgproc.hpp>
#include </home/pi/opencv-3.0.0/modules/highgui/include/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
	Mat cameraFrame;
	Mat flippedFrame;
	Mat croppedFrame;
	
	
	
	VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

	if (!stream1.isOpened()) { //check if video device has been initialised
		cout << "cannot open camera";
	}

	//unconditional loop
	while (true) {
		stream1.read(cameraFrame);
		flippedFrame = cameraFrame;
		flip(flippedFrame, cameraFrame, 1);
		
		
		
		croppedFrame = flippedFrame;
		
		croppedFrame = flippedFrame( Rect(0,0,640,384));
		
		resize(croppedFrame, croppedFrame, Size(croppedFrame.cols/0.8, croppedFrame.rows/0.8));
		namedWindow("cam",CV_WINDOW_AUTOSIZE);
		
		if (!croppedFrame.empty()) {
			imshow("cam", croppedFrame);
		}
		if (waitKey(30) >= 0)
			break;
	}	
	return 0;
}

