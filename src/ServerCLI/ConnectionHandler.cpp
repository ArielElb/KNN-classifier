#include "ServerCLI/ConnectionHandler.h"
#include "ServerCLI/ServerCLI.h"


void ConnectionHandler::operator()(DefaultIO *socketIO) {
    ServerCLI serverCLI(socketIO);
    serverCLI.start();
}
