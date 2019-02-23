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
	Mat front = Mat::zeros(640, 640, CV_8UC3);
	Mat back = Mat::zeros(640, 640, CV_8UC3);
	int ch, x, y;
	char imgName[] = { "calibration_000.bmp" };

	while (1) {
		capture >> frame;

		imshow("capture", frame);

		for (ch = 0; ch < 3; ch++) {
			for (y = 0; y < 640; y++) {
				for (x = 0; x < 640; x++) {

					back.at<Vec3b>(y, x)[ch] = frame.at<Vec3b>(y, x + 640)[ch];
					front.at<Vec3b>(y, x)[ch] = frame.at<Vec3b>(y, x)[ch];
				}
			}
		}
		imshow("front cam of ricoh", front);
		imshow("back cam of ricoh", back);

		char ch = waitKey(10);
		if (ch == 32) break;
		else if (ch == 'c') {
			imwrite(imgName, front);
			if (imgName[12] != '`')
				imgName[12]++;
			else if (imgName[13] != '`')
				imgName[13]++;
			else if (imgName[14] != '`')
				imgName[14]++;
			//imwrite(imgName, back);
			//imgName[12]++;			
		}

	}

}
