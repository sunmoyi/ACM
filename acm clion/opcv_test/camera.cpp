//
// Created by 孙启龙 on 2017/8/3.
//

#include "camera.h"

void camera(char* address)
{
    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
    }

    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    //namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    //int iLowH = 0;
    //int iHighH = 179;

    //int iLowS = 0;
    //int iHighS = 255;

    //int iLowV = 0;
    //int iHighV = 65;

    //Create trackbars in "Control" window
    //cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    //cvCreateTrackbar("HighH", "Control", &iHighH, 179);

    //cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    //cvCreateTrackbar("HighS", "Control", &iHighS, 255);

    //cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    //cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        //Mat imgHSV;
        //vector<Mat> hsvSplit;
        //cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

        //因为我们读取的是彩色图，直方图均衡化需要在HSV空间做
        //split(imgHSV, hsvSplit);
        //equalizeHist(hsvSplit[2],hsvSplit[2]);
        //merge(hsvSplit,imgHSV);
        //Mat imgThresholded;

        //inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

        //开操作 (去除一些噪点)
        //Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
        //morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

        //闭操作 (连接一些连通域)
        //morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

        //imshow("Thresholded Image", imgThresholded); //show the thresholded image
        //imshow("Original", imgOriginal); //show the original image
        //cvSaveImage("a.jpg", &imgThresholded);

        IplImage qpng;
        qpng = IplImage(imgOriginal);
        cvSaveImage(address, &qpng);

        //char key = (char) waitKey(300);
        //if(key == 27)
            break;
        //printf("%d %d %d %d %d %d\n", iLowH, iHighH, iLowS, iHighS, iLowV, iHighV);
    }
}
