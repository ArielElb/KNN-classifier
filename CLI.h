//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_CLI_H
#define ASS4_CLI_H

#include "UploadCommand.h"
#include "Command.h"
#include <vector>
class CLI {
public:
    void start();
    void initCommands();
private:
    std::vector<Command*> commands;
};

#endif //ASS4_CLI_H
