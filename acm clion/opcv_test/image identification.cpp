//
// Created by 孙启龙 on 2017/8/4.
//

#include "image_identification.h"
/*
pair<int, int> Change(char* txtaddress)
{
    ifstream stream(txtaddress);
    vector<int>x, y;
    int X, Y, R, G, B;
    while(stream >> X >> Y >> R >> G >> B)
        if(R == 255)
            x.push_back(X), y.push_back(Y);
    pair<double, double>ans = LeastSquare(x, y);
    double y1 = ans.first * 0 + ans.second;
    double y2 = ans.first * 360 + ans.second;
    pair<int, int>change(0, 0);
    if(y1 < 300)
        change.first = -1;
    else if (y1 > 340)
        change.second = 1;

    if(y2 < 300)
        change.second = -1;
    else if (y2 > 340)
        change.second = 1;
    return change;
}

pair<double, double> LeastSquare(vector<int>& x, vector<int>& y)
{
    double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for(int i = 0; i < x.size(); i++)
    {
        t1 += x[i] * x[i];
        t2 += x[i];
        t3 += x[i] * y[i];
        t4 += y[i];
    }
    double a = (t3 * x.size() - t2 * t4) / (t1 * x.size() - t2 * t2);
    double b = (t1 * t4 - t2 * t3) / (t1 * x.size() - t2 * t2);
    return make_pair(a, b);
};

void LeastSquareTest(pair<double, double>ans, char* picaddress)
{

}
*/
bool testblack(char* address, int num[3][2])
{
    int iLowH = num[0][0];
    int iHighH = num[0][1];

    int iLowS = num[1][0];
    int iHighS = num[1][1];

    int iLowV = num[2][0];
    int iHighV = num[2][1];

    Mat imgOriginal = imread(address);
    Mat imgHSV;
    vector<Mat> hsvSplit;
    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    //因为我们读取的是彩色图，直方图均衡化需要在HSV空间做
    split(imgHSV, hsvSplit);
    equalizeHist(hsvSplit[2],hsvSplit[2]);
    merge(hsvSplit,imgHSV);
    Mat imgThresholded;

    inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

    //开操作 (去除一些噪点)
    Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

    //闭操作 (连接一些连通域)
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

    IplImage qpng;
    qpng = IplImage(imgThresholded);
    cvSaveImage("/Users/sunqilong/Downloads/b.png", &qpng);

    return true;
}
/*
bool testyellow(char* address, int num[3][2])
{

}

bool testgreen(char* address, int num[3][2])
{

}

bool testorgin(char* address, int num[3][2])
{

}
 */