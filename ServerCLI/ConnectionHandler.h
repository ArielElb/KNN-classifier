//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_CONNECTIONHANDLER_H
#define ASS4_CONNECTIONHANDLER_H
#include "ServerCLI/ServerCLI.h"
class ConnectionHandler {
    public:
    ConnectionHandler() = default;
    virtual ~ConnectionHandler() = default;
    void operator()(DefaultIO *);

};


#endif //ASS4_CONNECTIONHANDLER_H
