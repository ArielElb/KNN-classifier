//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SETTINGSCOMMAND_H
#define ASS4_SETTINGSCOMMAND_H
#include "Command.h"
#include "DefaultIO.h"
#include "Database.h"

class SettingsCommand : public  Command {
    void execute() override;

    virtual ~SettingsCommand() = default;

public:
//constractor
    SettingsCommand(DefaultIO *pIo, Database *pDatabase);
    Database *database;
};



#endif //ASS4_SETTINGSCOMMAND_H
