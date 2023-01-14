#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H

#include "Menu.h"
#include "SocketIO.h"
class Server : public SocketIO {
    Menu menu;
public:
     int bindSocket(int port) override;
    int connect() override;
    std::string receive() override;
    void send(const std::string& data) override;
    void run();
    void checkUserInput();
    void getPort();
};


#endif //ASS4_SERVER_H
