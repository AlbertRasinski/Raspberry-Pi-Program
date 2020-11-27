#include "Server.h"

Server::Server(MotorData &motorData, AcquirePhoto &acquirePhoto){
    this->motorData = &motorData;
    this->acquirePhoto = &acquirePhoto;
}

Server::~Server(){};

void Server::startServer(){
    addressServer.sin_family = AF_INET;
    addressServer.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0", &addressServer.sin_addr);

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketServer, (sockaddr*)&addressServer, sizeof(addressServer));
    listen(socketServer, SOMAXCONN);

    clientSize = sizeof(addressClient);
    socketClient = accept(socketServer, (sockaddr*)&addressClient, &clientSize);
    close(socketServer);

    while(true){
        int numberOfBytes = recv(socketClient, inputBuffer, sizeof(inputBuffer), 0);
        if (numberOfBytes <= 0){
            std::cout<<"failed";
            motorData->setMotorLeft(0);
            motorData->setMotorRight(0);
            socketServer = socket(AF_INET, SOCK_STREAM, 0);
            bind(socketServer, (sockaddr*)&addressServer, sizeof(addressServer));
            listen(socketServer, SOMAXCONN);
            socketClient = accept(socketServer, (sockaddr*)&addressClient, &clientSize);
            close(socketServer);
        }else{
            motorData->setMotorLeft(inputBuffer[0] - 100);
            motorData->setMotorRight(inputBuffer[1] - 100);
            std::cout<<motorData->getMotorLeft()<<motorData->getMotorRight()<<std::endl;
            while(true){
                if (acquirePhoto->isReadyToSend()){
                    send(socketClient, &acquirePhoto->sizeBuffer[0], 4, 0);
                    send(socketClient, &acquirePhoto->photoBuffer[0], acquirePhoto->photoBuffer.size(), 0);
                    break;
                }
            }
        }
    }
}
