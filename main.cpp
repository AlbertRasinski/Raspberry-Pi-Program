#include "Server.h"
#include "MotorControl.h"

#include <iostream>

using namespace std;

int main(){
    MotorData motorData;
    MotorControl motorControl(motorData);
    AcquirePhoto acquirePhoto;
    Server server(motorData, acquirePhoto);

    ThreadTask *t1;
    t1 = &acquirePhoto;
    t1->startThread();

    server.startServer();

    t1->joinThread();

    /*while(1){
        std::cin >> x;
        motorData.setMotorRight(x);
        std::cin >> x;
        motorData.setMotorLeft(x);
        motorControl.motorDriverControl();
    }*/
    /*MotorData motorData;
    Server server(motorData);
    MotorControl motorControll(motorData);
    ThreadTask *motorThreadPointer = &motorControll;
    motorThreadPointer->startThread();

    server.startTransferring();
    motorThreadPointer->joinThread();*/
}
