//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SETTINGSCOMMAND_H
#define ASS4_SETTINGSCOMMAND_H
#include "Command.h"

class SettingsCommand : public  Command {
    void execute() override;

    virtual ~SettingsCommand() = default;

public:
//constractor
SettingsCommand() = default;
};



#endif //ASS4_SETTINGSCOMMAND_H