//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_CONNECTIONHANDLER_H
#define ASS4_CONNECTIONHANDLER_H
#include "SocketIO.h"
#include "ServerCLI/ServerCLI.h"
class ConnectionHandler {
    public:
    ConnectionHandler();
    virtual ~ConnectionHandler() = default;
    void operator()(DefaultIO *);

};


#endif //ASS4_CONNECTIONHANDLER_H
