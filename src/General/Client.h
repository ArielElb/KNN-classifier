#ifndef ASS4_CLIENT_H
#define ASS4_CLIENT_H

#include <algorithm>
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

#include "ClientCLI/ClientCLI.h"
#include "IO/SocketIO.h"
#include "Vector.h"

class Client {
    unsigned short port;
    const char *ip;
    void checkDistanceFunc(std::string &distance);
    void checkValidInput(std::string &input);
    unsigned short getPort(string portStr);
public:
    static int connectSock(unsigned short portNo);
    void run();
    Client(std::string ipStr, std::string portStr);
    ~Client() = default;

};

#endif //ASS4_CLIENT_H
