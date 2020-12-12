#include "Server.h"
#include "MotorControl.h"

#include <iostream>

using namespace std;

int main(){
    MotorData motorData;
    /*AcquirePhoto acquirePhoto;
    Server server(motorData, acquirePhoto);*/

    /*ThreadTask *t1;
    t1 = &acquirePhoto;
    t1->startThread();*/

    /*ThreadTask *t2;
    t2 = &motorData;
    t2->startThread();

    //server.startServer();

    //t1->joinThread();
    //t2->joinThread();*/
    int x;
    MotorControl motorControl(motorData);
    while(1){
        std::cin >> x;
        motorData.setMotorLeft(x);
        motorControl.motorDriverControl();
        motorData.doOnThread();
    }
}
