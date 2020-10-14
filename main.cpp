#include "Server.h"
#include "MotorControll.h"

#include <iostream>

using namespace std;

int main(){
    DataTransfer dataTransfer;
    Server server(dataTransfer);
    MotorControl motorControll(dataTransfer);
    ThreadTask *motorThreadPointer = &motorControll;
    motorThreadPointer->startThread();

    server.startTransferring();
    motorThreadPointer->joinThread();
}
