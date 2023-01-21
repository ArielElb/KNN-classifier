#include <chrono>
#include <thread>
#include "ClientCLI/ClassificationKnn.h"

ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;


}

void ClassificationKnn::execute() {
    std::string fromServer = this->dio->read();
    std::cout << fromServer;
    this->dio->write("1");
    // thread sleep for 1 sec
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
