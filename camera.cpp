
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
  VideoCapture stream1(0);   //0 is video device id.

  if (!stream1.isOpened()) { //check if video stream is there.
    cout << "cannot open camera";
  }

    //loop
  while (true) {
    Mat cameraFrame;
    stream1.read(cameraFrame);
    imshow("cam", cameraFrame);
    if (waitKey(30) >= 0)
    break;
  }
return 0;
}
