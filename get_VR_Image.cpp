#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;



void main() {

	VideoCapture capture(1);
	Mat frame;

	while (1) {
		capture >> frame;

		imshow("capture", frame);
		char ch = waitKey(10);
		if (ch == 32) break;

	}

}