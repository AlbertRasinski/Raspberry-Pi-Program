#ifndef DATATRANSFER_H
#define DATATRANSFER_H

class DataTransfer{
    public:
        DataTransfer();
        ~DataTransfer();

        int getMotorLeft();
        int getMotorRight();

        void setMotorLeft(int value);
        void setMotorRight(int value);

    private:
        int motorLeft;
        int motorRight;
};

#endif
