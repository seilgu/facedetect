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
	namedWindow("Edges", 1);

	for (;;) {
		Mat frame;
		cap >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("Edges", edges);
		if (waitKey(30) >= 0) break;
	}

	return 0;
}