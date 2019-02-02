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

	for (ch = 0; ch < 3; ch++) {
		for (R = 321; R >= 0; R--) {
			for (an = 46; an < 90; an = an + 1) {

				result.at<Vec3b>(321 + R, 321 + (int)(R / tan(an * rad))) = imgColor.at<Vec3b>(321 + (int)(R * sin(an * rad)), 321 + (int)(R * cos(an * rad)));

			}
		}
	}


	/*for (ch = 0; ch < 3; ch++) {
		for (y = 641; y > 320; y--) {
			for (x = 641; x > 320; x--) {

				result.at<Vec3b>(y, x)[ch] = imgColor.at<Vec3b>((int)(sin(45 * rad)*(y/2)) + (int)(y/2), (int)(cos(45 * rad)*(x/2)) + (int)(x/2))[ch];
				result.at<Vec3b>(y, x)[ch] = imgColor.at<Vec3b>((int)(sin(45 * rad)*R) + 321, (int)(cos(45 * rad)*(x / 2)) + 321)[ch];

			}
		}
	}

	printf("(int)sin(45 * rad)*y + y = %d, (int)cos(45 * rad)*x + x = %d\n", (int)(sin(45 * rad)*(641 / 2)) + (int)(641 / 2), (int)(cos(45 * rad)*(641 / 2)) + (int)(641 / 2));*/


	/*for (ch = 0; ch < 3; ch++) {
		result.at<Vec3b>(641, 641)[ch] = imgColor.at<Vec3b>(548, 548)[ch];
		result.at<Vec3b>(640, 641)[ch] = imgColor.at<Vec3b>(547, 548)[ch];
		result.at<Vec3b>(641, 640)[ch] = imgColor.at<Vec3b>(548, 547)[ch];
		result.at<Vec3b>(640, 640)[ch] = imgColor.at<Vec3b>(548, 548)[ch];
		result.at<Vec3b>(639, 640)[ch] = imgColor.at<Vec3b>(547, 548)[ch];
		result.at<Vec3b>(640, 639)[ch] = imgColor.at<Vec3b>(548, 547)[ch];

		
		result.at<Vec3b>(639, 639)[ch] = imgColor.at<Vec3b>(546, 546)[ch];
		result.at<Vec3b>(638, 639)[ch] = imgColor.at<Vec3b>(545, 546)[ch];
		result.at<Vec3b>(639, 638)[ch] = imgColor.at<Vec3b>(546, 545)[ch];


		result.at<Vec3b>(638, 638)[ch] = imgColor.at<Vec3b>(545, 545)[ch];
		result.at<Vec3b>(637, 638)[ch] = imgColor.at<Vec3b>(544, 545)[ch];
		result.at<Vec3b>(638, 637)[ch] = imgColor.at<Vec3b>(545, 544)[ch];

		result.at<Vec3b>(637, 637)[ch] = imgColor.at<Vec3b>(545, 545)[ch];
		result.at<Vec3b>(636, 637)[ch] = imgColor.at<Vec3b>(544, 545)[ch];
		result.at<Vec3b>(637, 636)[ch] = imgColor.at<Vec3b>(545, 544)[ch];


		result.at<Vec3b>(636, 636)[ch] = imgColor.at<Vec3b>(544, 544)[ch];
		result.at<Vec3b>(635, 636)[ch] = imgColor.at<Vec3b>(543, 544)[ch];
		result.at<Vec3b>(636, 635)[ch] = imgColor.at<Vec3b>(544, 543)[ch];


		result.at<Vec3b>(635, 635)[ch] = imgColor.at<Vec3b>(543, 543)[ch];
		result.at<Vec3b>(634, 635)[ch] = imgColor.at<Vec3b>(542, 543)[ch];
		result.at<Vec3b>(635, 634)[ch] = imgColor.at<Vec3b>(543, 542)[ch];

		result.at<Vec3b>(634, 634)[ch] = imgColor.at<Vec3b>(543, 543)[ch];
		result.at<Vec3b>(633, 634)[ch] = imgColor.at<Vec3b>(542, 543)[ch];
		result.at<Vec3b>(634, 633)[ch] = imgColor.at<Vec3b>(543, 542)[ch];


		result.at<Vec3b>(633, 633)[ch] = imgColor.at<Vec3b>(542, 542)[ch];
		result.at<Vec3b>(632, 632)[ch] = imgColor.at<Vec3b>(541, 541)[ch];
		result.at<Vec3b>(631, 631)[ch] = imgColor.at<Vec3b>(541, 541)[ch];
		result.at<Vec3b>(630, 630)[ch] = imgColor.at<Vec3b>(540, 540)[ch];
		result.at<Vec3b>(629, 629)[ch] = imgColor.at<Vec3b>(539, 539)[ch];
		result.at<Vec3b>(628, 628)[ch] = imgColor.at<Vec3b>(539, 539)[ch];
		result.at<Vec3b>(627, 627)[ch] = imgColor.at<Vec3b>(538, 538)[ch];

	}*/

	imshow("result", result);
	waitKey(50000);

}