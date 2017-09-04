//
// Created by 孙启龙 on 2017/8/3.
//

#ifndef OPCV_TEST_CAMERA_H
#define OPCV_TEST_CAMERA_H

#endif //OPCV_TEST_CAMERA_H
#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include  <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

void camera(char *address);

void write_pixel_to_txt(char* picaddress, char* txtaddress);
