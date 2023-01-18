
#include "ClassificationKnn.h"

//
// Created by arie1 on 1/18/2023.
//

ClassificationKnn::ClassificationKnn(DefaultIO *socketIO) {
    this->dio = socketIO;


}

void ClassificationKnn::execute() {
    std::string fromServer = this->dio->read();
    std::cout << fromServer << std::endl;
}
