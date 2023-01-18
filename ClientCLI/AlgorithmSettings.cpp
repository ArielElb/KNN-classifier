#include "AlgorithmSettings.h"

void AlgorithmSettings::execute() {
    // receive message from server
    std::string message;
    try {
        message = this->dio->read();
    } catch (...) {
        std::cout << "Error reading from server\n";
        return;
    }
    // print to screen
    std::cout << message << std::endl;
    // get response from user
    std::string userResponse;
    std::cin >> userResponse;
    this->dio->write(userResponse);
    if (userResponse == "") {
        return;
    }
    try {
        message = this->dio->read();
    } catch (...) {
        std::cout << "Error reading from server\n";
        return;
    }
    if (message != "") {
        std::cout << message;
    }
    return;
}