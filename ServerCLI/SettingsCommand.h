//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SETTINGSCOMMAND_H
#define ASS4_SETTINGSCOMMAND_H
#include "Command.h"
#include "Database.h"
#include "util.h"

class SettingsCommand : public  Command {
    Database *database;
public:
    SettingsCommand(DefaultIO *pIo, Database *pDatabase);
    virtual ~SettingsCommand() = default;
    void execute() override;
};



#endif //ASS4_SETTINGSCOMMAND_H
