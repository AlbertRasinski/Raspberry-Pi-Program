#ifndef ACQUIREPHOTO_H
#define ACQUIREPHOTO_H

#include <opencv2/opencv.hpp>
#include <cmath>
#include "ThreadTask.h"

class AcquirePhoto:public ThreadTask{
    public:
        AcquirePhoto();
        virtual ~AcquirePhoto();

        std::vector<uchar> photoBuffer;
        std::vector<uchar> sizeBuffer;

        virtual void doOnThread();

        bool isReadyToSend();

    private:
        const int FPS = 30;
        const int DELAY_IN_MILISEC = 1000000/FPS;
        const int PHOTO_WIDTH = 960;
        const int PHOTO_HEIGHT = 540;
        const int PHOTO_QUALITY = 50;
        const std::vector<int> PARAMS {cv::IMWRITE_JPEG_QUALITY, PHOTO_QUALITY};

        cv::VideoCapture camera;
        cv::Mat frame;
        bool readyToSend;
};

#endif
