#include "AcquirePhoto.h"

AcquirePhoto::AcquirePhoto(){
    camera.open(0);
    camera.set(3, PHOTO_WIDTH);
    camera.set(4, PHOTO_HEIGHT);

    sizeBuffer.push_back(0);
    sizeBuffer.push_back(0);
    sizeBuffer.push_back(0);
    sizeBuffer.push_back(0);
    readyToSend = false;
    copying = false;
}

AcquirePhoto::~AcquirePhoto(){};

void AcquirePhoto::doOnThread(){
    while(true){
        if (!copying){
            camera >> frame;
            readyToSend = false;
            cv::imencode(".jpg", frame, photoBuffer1, PARAMS);
            sizeBuffer[2] = floor(photoBuffer1.size() / 256);
            sizeBuffer[3] = photoBuffer1.size() - sizeBuffer[2] * 256;
            readyToSend = true;
            usleep(DELAY_IN_MILISEC);
        }
    }
}

bool AcquirePhoto::isReadyToSend(){
    if (readyToSend && !copying){
        copying = true;
        photoBuffer.assign(photoBuffer1.begin(), photoBuffer1.end());
        copying = false;
        readyToSend = false;
        return true;
    }else{
        return false;
    }
}
