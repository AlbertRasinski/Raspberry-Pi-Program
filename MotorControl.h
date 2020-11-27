#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include "MotorData.h"

class MotorControl{
    public:
        MotorControl(MotorData &motorData);
        ~MotorControl();

        void motorDriverControl();
    private:
        MotorData *motorData;

        const int STBY_PIN = 22;
        const int PWMA_PIN = 14;
        const int AI2_PIN = 30;
        const int AI1_PIN = 21;
        const int BI1_PIN = 24;
        const int BI2_PIN = 23;
        const int PWMB_PIN = 25;
};

#endif
