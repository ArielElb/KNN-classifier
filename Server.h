#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H

#include "Menu.h"
#include "SocketIO.h"
class Server{
    Menu menu;
public:
    void run();
    void checkUserInput();
    void getPort();
    Server();
};


#endif //ASS4_SERVER_H
