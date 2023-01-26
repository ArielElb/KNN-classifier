#include <thread>
#include "ClientCLI/ClassificationKnn.h"


ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;
}

/*
 * Client side option 3, reads message from server
 */
void ClassificationKnn::execute() {
    std::string fromServer;
    try {
        fromServer = dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
        return;
    }
    std::cout << fromServer;
    this->dio->write("1");
    // thread sleep for 1 sec
}
