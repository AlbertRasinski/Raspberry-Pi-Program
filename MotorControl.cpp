#include "MotorControl.h"

MotorControl::MotorControl(MotorData &motorData){
    this->motorData = &motorData;

    wiringPiSetup();
    softPwmCreate(PWMA_PIN, 0, 100);
    softPwmCreate(PWMB_PIN, 0, 100);
    pinMode(AI1_PIN, OUTPUT);
    pinMode(AI2_PIN, OUTPUT);
    pinMode(BI1_PIN, OUTPUT);
    pinMode(BI2_PIN, OUTPUT);
    pinMode(STBY_PIN, OUTPUT);
    digitalWrite(STBY_PIN, 1);
}

MotorControl::~MotorControl(){
    digitalWrite(AI1_PIN, 0);
    digitalWrite(AI2_PIN,0);
    digitalWrite(BI1_PIN, 0);
    digitalWrite(BI2_PIN,0);
    digitalWrite(STBY_PIN,0);
}

void MotorControl::motorDriverControl(){
    if (motorData->getMotorRight() > 0){
        digitalWrite(AI1_PIN, 0);
        digitalWrite(AI2_PIN, 1);
    }else{
        digitalWrite(AI1_PIN, 1);
        digitalWrite(AI2_PIN, 0);
    }

    if (motorData->getMotorLeft() > 0){
        digitalWrite(BI1_PIN, 1);
        digitalWrite(BI2_PIN, 0);
    }else{
        digitalWrite(BI1_PIN, 0);
        digitalWrite(BI2_PIN, 1);
    }

    softPwmWrite(PWMA_PIN, abs(motorData->getMotorRight()));
    softPwmWrite(PWMB_PIN, abs(motorData->getMotorLeft()));
}

