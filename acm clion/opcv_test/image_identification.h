//
// Created by 孙启龙 on 2017/8/4.
//

#ifndef OPCV_TEST_IMAGE_IDENTIFICATION_H
#define OPCV_TEST_IMAGE_IDENTIFICATION_H

#endif //OPCV_TEST_IMAGE_IDENTIFICATION_H

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include  <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int black[3][2] = {{0, 179}, {0, 255}, {0, 65}};

//pair<int, int> Change(char* txtaddress);

//pair<double, double> LeastSquare(vector<int>& x, vector<int>& y);

//void LeastSquareTest(pair<double, double>ans, char* picaddress);

bool testblack(char* address, int num[3][2]);

//bool testyellow(char* address, int num[3][2]);

//bool testgreen(char* address, int num[3][2]);

//bool testorgin(char* address, int num[3][2]);