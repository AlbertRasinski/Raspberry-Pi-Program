#ifndef MOTORDATA_H
#define MOTORDATA_H

#include "INA219.h"
#include "ThreadTask.h"
#include <chrono>
#include <iostream>

class MotorData:public ThreadTask{
    public:
        MotorData();
        virtual ~MotorData();

        int getMotorLeft();
        int getMotorRight();

        void setMotorLeft(int value);
        void setMotorRight(int value);

        virtual void doOnThread();

    private:
        int motorLeftSP;
        int motorRightSP;
        int motorLeft;
        int motorRight;

        const unsigned char ADDRESS_LEFT = 0x40;
        const unsigned char ADDRESS_RIGHT = 0x41;
        const float SHUNT_OHMS = 0.1;
        const float MAX_EXPECTED_AMPS = 0.8;
        const int CYCLES_PWM = 500;
        const int PERIOD_PWM_MICRO = 10000;
        const int SAMPLE_TIME = CYCLES_PWM * PERIOD_PWM_MICRO;

        INA219 currentMeasureLeft;
        //INA219 currentMeasureRight;

        const double EQUATION_A = 1.0;
        const double EQUATION_B = 1.0;
        const double MIN_VALUE = 40;
        const int MAX_ROTATION = 630;

        int currentToRotation(float value);
};

#endif
