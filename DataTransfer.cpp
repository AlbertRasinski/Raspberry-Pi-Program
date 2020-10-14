#include "DataTransfer.h"

DataTransfer::DataTransfer(){
    motorLeft = 0;
    motorRight = 0;
}

DataTransfer::~DataTransfer(){}

int DataTransfer::getMotorLeft(){
    return motorLeft;
}

int DataTransfer::getMotorRight(){
    return motorRight;
}

void DataTransfer::setMotorLeft(int value){
    motorLeft = value;
}

void DataTransfer::setMotorRight(int value){
    motorRight = value;
}
