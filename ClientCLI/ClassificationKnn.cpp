#include <chrono>
#include <thread>
#include "ClassificationKnn.h"

ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;


}

void ClassificationKnn::execute() {
    std::string fromServer = this->dio->read();
    std::cout << fromServer;
    // thread sleep for 1 sec
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
