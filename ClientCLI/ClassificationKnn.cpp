#include "ClassificationKnn.h"

ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;


}

void ClassificationKnn::execute() {
    std::string fromServer = this->dio->read();
    std::cout << fromServer << std::endl;
}
