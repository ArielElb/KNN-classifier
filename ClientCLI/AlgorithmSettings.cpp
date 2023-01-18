#include "AlgorithmSettings.h"

void AlgorithmSettings::execute() {
    // receive message from server
    std::string message = this->dio->read();
    // print to screen
    std::cout << message << std::endl;
    // get response from user
    std::string userResponse;
    std::cin >> userResponse;
    this->dio->write(userResponse);
    if (userResponse == "") {
        return;
    }
    std::string input;
    std::cin >> input;

}