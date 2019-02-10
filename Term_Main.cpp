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
	Mat right = Mat::zeros(640, 720, CV_8UC3);
	int ch, x, y;
	char imgName[] = { "calibration_k.bmp" };

	while (1) {
		capture >> frame;

		imshow("capture", frame);

		for (ch = 0; ch < 3; ch++) {
			for (y = 0; y < 640; y++) {
				for (x = 0; x < 640; x++) {

					right.at<Vec3b>(y, x)[ch] = frame.at<Vec3b>(y, x + 640)[ch];

				}
			}
		}
		imshow("right side of ricoh", right);

		char ch = waitKey(10);
		if (ch == 32) break;
		else if (ch == 'c') {
			imwrite(imgName, right);
			imgName[12]++;
		}

	}

}