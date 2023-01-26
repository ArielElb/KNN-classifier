#include "ClientCLI/DisplayClassiffications.h"

DisplayClassiffications::DisplayClassiffications(DefaultIO *dio) {
    this->dio = dio;
}

/**
 * Reads classifications/error message from server and prints to screen
 */
void DisplayClassiffications::execute() {
    // display the data file that is already uploaded to the server
    std::string fromServer;
    try {
        fromServer = this->dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
        return;
    }
    std::cout << fromServer ;
    if (fromServer == "please upload data\nplease classify the data\n") {
        this->dio->write("1");
        return;
    }
    else if (fromServer == "please classify the data\n") {
        this->dio->write("1");
        return;
    }
    else if (fromServer == "please upload data\n") {
        this->dio->write("1");
        return;
    }

    else {
        string input;
        bool valid = true;
        do {
            if (!valid) {
               std::cout << "Press enter to continue" << std::endl;
            }
            getline(std::cin, input);
            valid = input.empty();
        } while (!input.empty());
        this->dio->write(input);
    }
}
