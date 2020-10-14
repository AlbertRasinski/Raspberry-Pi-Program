#include "Server.h"

Server::Server(DataTransfer &data){
    dataTransfer = &data;

    addressServer.sin_family = AF_INET;
    addressServer.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0", &addressServer.sin_addr);

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketServer, (sockaddr*)&addressServer, sizeof(addressServer));
    listen(socketServer, SOMAXCONN);

    clientSize = sizeof(addressClient);

    socketClient = accept(socketServer, (sockaddr*)&addressClient, &clientSize);

    close(socketServer);
}

Server::~Server(){};

void Server::startTransferring(){
    while(true){
        int numberOfBytes = recv(socketClient, buffer, sizeof(buffer), 0);
        std::cout<<"0";
        if (numberOfBytes <= 0){
            dataTransfer->setMotorLeft(0);
            dataTransfer->setMotorRight(0);
            socketServer = socket(AF_INET, SOCK_STREAM, 0);
            bind(socketServer, (sockaddr*)&addressServer, sizeof(addressServer));
            listen(socketServer, SOMAXCONN);
            socketClient = accept(socketServer, (sockaddr*)&addressClient, &clientSize);
            close(socketServer);
        }else{
            dataTransfer->setMotorLeft(buffer[0] - 100);
            dataTransfer->setMotorRight(buffer[1] - 100);
            send(socketClient, buffer, numberOfBytes + 1, 0);
        }
    }
}
