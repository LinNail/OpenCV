// ScanImg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "ScanWays.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	int divideWith;		//convert our input string to number - C++ style
	stringstream s;
	s << argv[2];
	s >> divideWith;
	if(!s)
	{
		cout << "Invalid number entered for dividing. " << endl;
		return -1;
	}

	uchar table[256];
	for(int i = 0; i < 256; ++i)
		table[i] = divideWith*(i/divideWith);

	char* ImagePath = "../Images/Sample.jpg";
	Mat img = imread(ImagePath);

	if(!img.data)
	{
		cout << "Load the image ERROR!" << endl;
		return -1;
	}
	
	//Mat I1, I2, I3, I4;
	//I1 = I2 = I3 = I4 = img.clone();

	double t1 = (double)getTickCount();
	ScanWays::ScanImageAndReduceC(img, table);
	t1 = ((double)getTickCount() - t1)/getTickFrequency();
	cout << "Times of the Efficient Way pass in seconds: " << t1 << endl;

	//namedWindow("万虹萱", CV_WINDOW_FULLSCREEN);
	//imshow("万虹萱",img);

	double t2 = (double)getTickCount();
	ScanWays::ScanImageAndReduceIterator(img, table);
	t2 = ((double)getTickCount() - t2)/getTickFrequency();
	cout << "Times of the Iterator Method pass in seconds: " << t2 << endl;

	double t3 = (double)getTickCount();
	ScanWays::ScanImageAndReduceRandomAccess(img, table);
	t3 = ((double)getTickCount() - t3)/getTickFrequency();
	cout << "Times of the On-The-Fly pass in seconds: " << t3 << endl;

	double t4 = (double)getTickCount();

	Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.data;
	for(int i = 0; i < 256; ++i)
		p[i] = table[i];
	LUT(img, lookUpTable, img);

	t4 = ((double)getTickCount() - t4)/getTickFrequency();
	cout << "Times of the LUT pass in seconds: " << t4 <<endl;

	waitKey(0);
	return 0;
}

