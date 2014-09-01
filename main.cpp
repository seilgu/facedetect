#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
	cv::VideoCapture cap(0);

	if (!cap.isOpened()) return -1;

	Mat edges;
	//namedWindow("Edges", WINDOW_OPENGL);
	namedWindow("original", 1);
	namedWindow("blurred", 1);

	for (;;) {
		Mat frame, blurred;
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		GaussianBlur(frame, blurred, Size(7,7), 1.5, 1.5);
		Canny(frame, frame, 0, 30, 3);
		Canny(blurred, blurred, 0, 30, 3);
		imshow("original", frame);
		imshow("blurred", blurred);
		//imshow("Edges", edges);
		if (waitKey(30) > 0) break;
	}

	return 0;
}