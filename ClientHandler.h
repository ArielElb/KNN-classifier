//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_CLIENTHANDLER_H
#define ASS4_CLIENTHANDLER_H
#include "DefaultIO.h"

class ClientHandler {
private:
    int clientSocket;
    int serverSocket;
    DefaultIO *dio;
    int
public:
    virtual void handleClient(int clientSocket) = 0;
    virtual ~ClientHandler() = default;

};

};


#endif //ASS4_CLIENTHANDLER_H
