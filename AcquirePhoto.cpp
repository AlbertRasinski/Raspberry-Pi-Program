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
}

AcquirePhoto::~AcquirePhoto(){};

void AcquirePhoto::doOnThread(){
    while(true){
        camera >> frame;
        readyToSend = false;

        cv::imencode(".jpg", frame, photoBuffer, PARAMS);
        sizeBuffer[2] = floor(photoBuffer.size() / 256);
        sizeBuffer[3] = photoBuffer.size() - sizeBuffer[2] * 256;

        readyToSend = true;

        usleep(DELAY_IN_MILISEC);
    }
}

bool AcquirePhoto::isReadyToSend(){
    if (readyToSend){
        readyToSend = false;
        return true;
    }else{
        return false;
    }
}
