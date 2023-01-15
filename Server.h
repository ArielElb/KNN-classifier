#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H
#include <string>
#include "Database.h"
#include "Menu.h"
#include "Vector.h"
#include "SocketIO.h"
#include "ServerCLI.h"
class Server{
    Database* database{};
    int port{};
public:
    Server() = default;
    ~Server() = default;
    int bindSock(int port);
    static int extractPort(std::string portStr);
    static Vector extractVector(std::string &input);
    static void checkUserInput(unsigned long vectorSize, Database &database, int k);
    Database* getDatabase();
    void run();
    Server(std::string portStr, std::string pathIn);
};
#endif //ASS4_SERVER_H
