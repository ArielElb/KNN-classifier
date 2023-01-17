#ifndef ASS4_CLIENT_H
#define ASS4_CLIENT_H
#include <arpa/inet.h>
#include <cstdio>
#include <sys/socket.h>
#include "IO/SocketIO.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "Vector.h"
#include "ClientCLI/ClientCLI.h"

class Client {
    int port;
    const char *ip;
//    struct sockaddr_in serv_addr{};
    void checkDistanceFunc(std::string &distance);
    void checkValidInput(std::string &input);
    int getPort(string portStr);
    int connectSock();
public:
    void run();
    Client(std::string ipStr, std::string portStr);
    ~Client() = default;

};

#endif //ASS4_CLIENT_H
