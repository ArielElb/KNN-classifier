//
// Created by arie1 on 1/16/2023.
//

#include "ClientCLI.h"

#include <utility>
#include "IO/DefaultIO.h"


void ClientCLI::initCommands() {
    commands.push_back(new DisplayClassiffications(new FileCSVIO(path), this->dio));
    commands.push_back(new DownloadFile(new FileCSVIO(path),this->dio));
}


void ClientCLI::start(int i) {
    commands[i]->execute();
}

ClientCLI::ClientCLI(DefaultIO *dio) {
    this->dio = dio;
    initCommands();

}

