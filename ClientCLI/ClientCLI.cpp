//
// Created by arie1 on 1/16/2023.
//

#include "ClientCLI.h"

#include <utility>
#include "IO/DefaultIO.h"


void ClientCLI::initCommands() {
    commands.push_back(new DisplayClassiffications(new FileIO(path), this->dio));
    commands.push_back(new DownloadFile(new FileIO(path),this->dio));
    commands.push_back(new UploadFile(this->dio));
    commands.push_back(new AlgorithmSettings(this->dio));
    commands.push_back(new DisplayClassiffications(this->dio));
    commands.push_back(new DownloadFile(this->dio));
}


void ClientCLI::start() {
    int input;
    string str = this->dio->read();
    std::cout << str << std::endl;
    std::cin >> input;
    string s = std::to_string(input);
    this->dio->write(s);
    std::cin >> input;
}

ClientCLI::ClientCLI(DefaultIO *dio) {
    this->dio = dio;
    initCommands();

}

