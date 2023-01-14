//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_CLI_H
#define ASS4_CLI_H

#include "UploadCommand.h"
#include "Command.h"
#include <vector>
#include "Menu.h"
class CLI {
public:
    CLI(); //constructor
    virtual ~CLI(){
        delete menu;
    } //destructor
    Menu* menu = new Menu();
    void start();
private:
    std::vector<Command*> commands;
    void initCommands();
};

#endif //ASS4_CLI_H
