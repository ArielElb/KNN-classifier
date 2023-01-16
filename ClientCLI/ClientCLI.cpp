//
// Created by arie1 on 1/16/2023.
//

#include "ClientCLI.h"

#include <utility>
#include "IO/DefaultIO.h"


void ClientCLI::initCommands() {
    commands.push_back(new DisplayClassiffications(new FileCSVIO(path)));
    commands.push_back(new DownloadFile(new FileCSVIO(path)));
}

ClientCLI::ClientCLI(DefaultIO *dio, std::string path) {
    this->dio = dio;
    this->path = std::move(path);
    initCommands();

}

void ClientCLI::start(int i) {
    commands[i]->execute();
}

