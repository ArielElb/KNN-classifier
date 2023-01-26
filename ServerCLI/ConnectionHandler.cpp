#include "ServerCLI/ConnectionHandler.h"
#include "ServerCLI/ServerCLI.h"

/*
 * Functor class for opening a unique connection handler for each client. Passed to thread upon construction
 */
void ConnectionHandler::operator()(DefaultIO *socketIO) {
    ServerCLI serverCLI(socketIO);
    serverCLI.start();
}
