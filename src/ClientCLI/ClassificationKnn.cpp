#include <chrono>
#include <thread>
#include "ClientCLI/ClassificationKnn.h"

ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;
}

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
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
