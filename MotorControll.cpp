#include "MotorControll.h"

MotorControl::MotorControl(DataTransfer &data){
    dataTransfer = &data;

    wiringPiSetup();
    pinMode(PIN_DIRECTION_MOTOR, OUTPUT);
    pinMode(PIN_LEFT_MOTOR, OUTPUT);
    pinMode(PIN_RIGHT_MOTOR, OUTPUT);
}

MotorControl::~MotorControl(){
    digitalWrite(PIN_DIRECTION_MOTOR, 0);
    digitalWrite(PIN_LEFT_MOTOR,0);
    digitalWrite(PIN_RIGHT_MOTOR,0);
}

void MotorControl::doOnThread(){
    clock_t timer1 = clock();
    clock_t timer2 = clock();

    while(true){
        if (dataTransfer->getMotorLeft() > 0){
            digitalWrite(PIN_DIRECTION_MOTOR, 1);
        }else{
            digitalWrite(PIN_DIRECTION_MOTOR, 0);
        }

        if (dataTransfer->getMotorLeft() != 0){
            double timeToChange = TIME_CONST / dataTransfer->getMotorLeft();
            timer2 = clock();
            if (timeToChange < (double)(timer2 - timer1) / CLOCKS_PER_SEC){
                timer1 = clock();
                //std::cout<<"id: "<<thread<<std::endl;
                /*digitalWrite(PIN_LEFT_MOTOR,1);
                usleep(500);
                digitalWrite(PIN_LEFT_MOTOR,0);*/

                //usleep odjecie 500us od drugiego
            }
        }
        /*if (dataTransfer->getMotorLeft() != 0){
            double timeToChange = TIME_CONST / dataTransfer->getMotorLeft();
            clock_t timer2 = clock();
            std::cout<< dataTransfer->getMotorLeft() << " " << dataTransfer->getMotorRight() << std::endl;
            std::cout<<"timeToChange: "<<timeToChange<< " (double)(timer2 - timer1) / CLOCKS_PER_SEC: " << (double)(timer2 - timer1) / CLOCKS_PER_SEC<<std::endl;
            if (timeToChange < (double)(timer2 - timer1) / CLOCKS_PER_SEC){

                //digitalWrite(PIN_LEFT_MOTOR,1);

                timer1 = clock();
            }
        }
        sleep(1000);*/
    }
}
