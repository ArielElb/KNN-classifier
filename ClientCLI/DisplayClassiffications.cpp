//
// Created by arie1 on 1/16/2023.
//

#include "DisplayClassiffications.h"

DisplayClassiffications::DisplayClassiffications(DefaultIO *dio) {
    this->dio = dio;
}

void DisplayClassiffications::execute() {
    // display the data file that is already uploaded to the server
    std::string fromServer = this->dio->read();

    std::cout << fromServer;
    string input;
    std::cin.get();
    getline(std::cin, input);
    this->dio->write(input);

}
