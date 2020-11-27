#ifndef SERVER_H
#define SERVER_H

#include "MotorData.h"
#include "AcquirePhoto.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

class Server{
    public:
        Server(MotorData &motorData, AcquirePhoto &acquirePhoto);
        ~Server();

        void startServer();

    private:
        const int PORT = 4831;

        sockaddr_in addressServer;
        int socketServer;
        sockaddr addressClient;
        int socketClient;
        socklen_t clientSize;

        char inputBuffer[2];

        MotorData *motorData;
        AcquirePhoto *acquirePhoto;
};

#endif
