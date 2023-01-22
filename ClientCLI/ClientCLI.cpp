#include "ClientCLI/ClientCLI.h"
#include <iostream>
#include <string>
#include "IO/DefaultIO.h"


void ClientCLI::initCommands() {
    commands.push_back(new UploadFile(this->dio));
    commands.push_back(new AlgorithmSettings(this->dio));
    commands.push_back(new ClassificationKnn(this->dio));
    commands.push_back(new DisplayClassiffications(this->dio));
    commands.push_back(new DownloadFile(this->dio));
}

void ClientCLI::start() {
    int input = 0;
    std::string menu;
    do {
        //read menu from user
        try {
            menu = this->dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket." << std::endl;
            return;
        }
        // print the menu
        while (true) {
            std::cout << menu << std::endl;
            // read the choice from the user
            std::string s;
            std::getline(std::cin, s);
            try {
                input = std::stoi(s);
            } catch (...) {
                input = 0;
            }
            if ((input >= 1 && input <= 5) || input == 8) {
                this->dio->write(s);
                if (input != 8) {
                    commands[input - 1]->execute();
                }
                break;
            } else {
                std::cout << "Invalid input" << std::endl;
            }
        }
    } while (input != 8);
}


ClientCLI::ClientCLI(DefaultIO *dio) {
    this->dio = dio;
    initCommands();

}

