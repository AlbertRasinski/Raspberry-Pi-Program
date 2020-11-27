#ifndef MOTORDATA_H
#define MOTORDATA_H

class MotorData{
    public:
        MotorData();
        ~MotorData();

        int getMotorLeft();
        int getMotorRight();

        void setMotorLeft(int value);
        void setMotorRight(int value);

    private:
        int motorLeft;
        int motorRight;
};

#endif
