//
// Created by arie1 on 1/16/2023.
//

#include "ConnectionHandler.h"


ConnectionHandler::ConnectionHandler() = default;

void ConnectionHandler::operator()(DefaultIO *socketIO) {
    ServerCLI serverCLI(socketIO);
    serverCLI.start();
}
