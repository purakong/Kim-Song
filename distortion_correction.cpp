#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

#define PI 3.1415926535897
#define rad PI/180

using namespace cv;

int main(void)

{
	Mat imgColor = imread("fisheye.bmp", CV_LOAD_IMAGE_COLOR);
	Mat result = imgColor.clone();

	int width = imgColor.cols;
	int height = imgColor.rows;
	int x, y, ch, R = 321, an;

	imshow("test1", imgColor);

	/*for (ch = 0; ch < 3; ch++) {
		for (R = 321; R >= 0; R--) {
			for (an = 46; an < 90; an = an + 1) {

				result.at<Vec3b>(321 + R, 321 + (int)(R / tan(an * rad))) = imgColor.at<Vec3b>(321 + (int)(R * sin(an * rad)), 321 + (int)(R * cos(an * rad)));

			}
			for (an = 0; an < 45; an++) {

				result.at<Vec3b>(321 + (int)(R / tan(an * rad)), 321 + R) = imgColor.at<Vec3b>(321 + (int)(R * sin(an * rad)), 321 + (int)(R * cos(an * rad)));

			}
		}
	}*/


	for (ch = 0; ch < 3; ch++) {
		for (y = 641; y > 320; y--) {
			for (x = 641; x > 320; x--) {

				result.at<Vec3b>(y, x)[ch] = imgColor.at<Vec3b>((int)(sin(45 * rad)*(y/2)) + (int)(y/2), (int)(cos(45 * rad)*(x/2)) + (int)(x/2))[ch];
				//result.at<Vec3b>(y, x)[ch] = imgColor.at<Vec3b>((int)(sin(45 * rad)*R) + 321, (int)(cos(45 * rad)*(x / 2)) + 321)[ch];

			}
		}
	}

	printf("(int)sin(45 * rad)*y + y = %d, (int)cos(45 * rad)*x + x = %d\n", (int)(sin(45 * rad)*(641 / 2)) + (int)(641 / 2), (int)(cos(45 * rad)*(641 / 2)) + (int)(641 / 2));



	imshow("result", result);
	waitKey(50000);

}
