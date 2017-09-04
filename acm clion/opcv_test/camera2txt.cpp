//
// Created by 孙启龙 on 2017/8/3.
//

#include "camera.h"

using namespace std;
using namespace cv;

void write_pixel_to_txt(char* picaddress, char* txtaddress)
{
    Mat const image = imread(picaddress);
    ofstream stream(txtaddress);

    for(int row = 0; row != image.rows; row++)
    {
        auto ptr = image.ptr<uchar>(row);
        for(int col = 0; col != image.cols; col++)
        {
            stream << row << " " << col << " "  << static_cast<int>(ptr[2]) << ", " << static_cast<int>(ptr[1]) << ", " << static_cast<int>(ptr[0]) << endl;
            ptr += 3;
        }
    }
    stream.close();
}