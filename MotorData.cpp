#include "MotorData.h"

MotorData::MotorData():currentMeasureLeft(SHUNT_OHMS, MAX_EXPECTED_AMPS, ADDRESS_LEFT){
    motorLeft = 0;
    motorRight = 0;

    currentMeasureLeft.configure(RANGE_16V, GAIN_2_80MV, ADC_12BIT, ADC_12BIT);
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

int MotorData::currentToRotation(float value){
    double maxValue = EQUATION_A_MIN * motorLeft + EQUATION_B_MIN;
    if (value <= maxValue){
        return (value - MIN_VALUE) / (maxValue - MIN_VALUE) * 630;
    }else{
        return 0;
    }
}

void MotorData::doOnThread(){
    double sum = 0;
    int counter = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    while(true){
        end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() < SAMPLE_TIME){
            sum += currentMeasureLeft.current();
            ++counter;
        }else{
            begin = std::chrono::steady_clock::now();
            end = std::chrono::steady_clock::now();
            std::cout << "Current:  " << sum / counter << "   " << counter << std::endl;
            counter = 0;
            sum = 0;
            break;
        }
    }
}
