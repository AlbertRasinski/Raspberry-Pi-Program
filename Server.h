#ifndef SERVER_H
#define SERVER_H

#include "DataTransfer.h"

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

class Server{
    public:
        Server(DataTransfer &data);
        ~Server();

        void startTransferring();

    private:
        const int PORT = 4831;

        sockaddr_in addressServer;
        int socketServer;
        sockaddr addressClient;
        int socketClient;

        socklen_t clientSize;

        char buffer[2];

        DataTransfer *dataTransfer;
};

#endif
