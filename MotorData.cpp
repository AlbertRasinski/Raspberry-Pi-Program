#include "MotorData.h"

MotorData::MotorData(){
    motorLeft = 0;
    motorRight = 0;
}

MotorData::~MotorData(){}

int MotorData::getMotorLeft(){
    return motorLeft;
}

int MotorData::getMotorRight(){
    return motorRight;
}

void MotorData::setMotorLeft(int value){
    motorLeft = value;
}

void MotorData::setMotorRight(int value){
    motorRight = value;
}
