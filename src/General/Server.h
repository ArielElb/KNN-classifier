#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H
#include <string>
#include <sys/socket.h>
#include "Database.h"
#include "Vector.h"
#include "ServerCLI/ServerCLI.h"
#include "IO/DefaultIO.h"
#include "IO/SocketIO.h"
class Server{
    Database* database{};
    int port{};
public:
    Server() = default;
    ~Server() = default;
    static int bindSock(unsigned short port);
    static int extractPort(std::string portStr);
    static Vector extractVector(std::string &input);
    static void checkUserInput(unsigned long vectorSize, Database &database, int k);
    void run();
    explicit Server(std::string portStr);
};
#endif //ASS4_SERVER_H
