//
// Created by 孙启龙 on 2017/8/3.
//

#include "camera.h"
#include "image_identification.h"

using namespace std;
using namespace cv;

int main (void)
{
    char pngpath[] = "/Users/sunqilong/Downloads/a.png";
    char txtpath[] = "/Users/sunqilong/Downloads/a.txt";
    camera(pngpath);
    //write_pixel_to_txt(pngpath, txtpath);
    testblack(pngpath, black);
}