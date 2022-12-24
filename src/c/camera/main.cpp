#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture capture("/dev/video0");
    if(capture.isOpened())
    {
        cout<<"Open USB camera success"<<endl;
    }
    Mat frame;
    while (capture.isOpened())
    {
        capture >> frame;
        imshow("capture", frame);
        char key = static_cast<char>(cvWaitKey(10));//控制视频流的帧率，10ms一帧
        if (key == 27)  //按esc退出
            break;               
    }
    return 0;
}