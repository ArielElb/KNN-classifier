//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_CLI_H
#define ASS4_CLI_H

#include "UploadCommand.h"
#include "Command.h"
#include <vector>
#include "Menu.h"
#include "DefaultIO.h"
#include "Database.h"

class CLI {
public:
    explicit CLI(DefaultIO *dio);
    virtual ~CLI();
    void start();
private:
    Database *database{};
    DefaultIO *dio;
    std::vector<Command *> commands;
    void initCommands();
};

#endif //ASS4_CLI_H
