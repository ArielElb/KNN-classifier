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
        std::cin.ignore();
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
