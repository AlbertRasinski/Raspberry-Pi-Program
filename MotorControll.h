#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "ThreadTask.h"
#include "wiringPi.h"
#include "DataTransfer.h"
#include <time.h>
#include <iostream>
#include <math.h>

class MotorControl:public ThreadTask{
    public:
        MotorControl(DataTransfer &data);
        virtual ~MotorControl();

        virtual void doOnThread();

    private:
        const int PIN_DIRECTION_MOTOR = 29;
        const int PIN_LEFT_MOTOR = 25;
        const int PIN_RIGHT_MOTOR = 28;

        const int MAX_SPEED_KM_H = 8;
        const int RADIUS_OF_THE_WHEELS_MM = 50;
        const double TIME_CONST = M_PI * 2 *RADIUS_OF_THE_WHEELS_MM / 1000 / MAX_SPEED_KM_H / 1000 * 3600;

        DataTransfer *dataTransfer;
};

#endif
