#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class ScanWays
{
public:
	static Mat& ScanImageAndReduceC(Mat& I, const uchar* const table);
	static Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table);
	static Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table);
};

/*class ScanWays
{
public:
	static Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
	//accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	int channels = I.channels();

	int nRows = I.rows * channels;
	int nCols = I.cols;

	if(I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i,j;
	uchar* p;
	for(i = 0; i < nRows; ++i)
	{
		p = I.ptr<uchar>(i);
		for(j = 0; j < nCols; ++j)
		{
			p[j] = table[p[j]];
		}
	}
	return I;
}

	static Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
	//accept only char type matrics
	CV_Assert(I.depth() != sizeof(uchar));

	const int channels = I.channels();
	switch(channels)
	{
	case 1:
		{
			MatIterator_<uchar> it, end;
			for(it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
				*it = table[*it];
			break;
		}
	case 3:
		{
			MatIterator_<Vec3b> it, end;
			for(it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
			{
				(*it)[0] = table[(*it)[0]];
				(*it)[1] = table[(*it)[1]];
				(*it)[2] = table[(*it)[2]];
			}
		}
	}
	return I;
}

	static Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
	//accept only char type matrics
	CV_Assert(I.depth() != sizeof(uchar));

	const int channels = I.channels();
	switch(channels)
	{
	case 1:
		{
			for(int i = 0; i < I.rows; ++i)
				for(int j = 0; j < I.cols; ++j)
					I.at<uchar>(i,j) = table[I.at<uchar>(i, j)];
			break;
		}
	case 3:
		{
			Mat_<Vec3b> _I = I;

			for(int i = 0; i < I.rows; ++i)
				for(int j = 0; j < I.cols; ++j)
				{
					_I(i, j)[0] = table[_I(i,j)[0]];
					_I(i, j)[1] = table[_I(i,j)[1]];
					_I(i, j)[2] = table[_I(i,j)[2]];
				}
			I = _I;
			break;
		}
	}

	return I;
}
};*/


