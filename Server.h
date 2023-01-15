#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H
#include <string>
#include "Database.h"
#include "Menu.h"
#include "Vector.h"
#include "SocketIO.h"

struct serverArgs {
    int client_sock;
    Database* database;
};

class Server{
    Database database;
    int port;
    void checkUserInput();
    void* connectionHandler(void* inputArgs);
    int bindSock(int port);
    void getPort(std::string portStr);
    Vector extractVector(std::string &input);
    void checkUserInput(unsigned long vectorSize, Database &database, int k);
public:
    void run();
    Server(std::string portStr, std::string pathIn);
    ~Server() = default;
};
#endif //ASS4_SERVER_H
