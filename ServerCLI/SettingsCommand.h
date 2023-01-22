#ifndef ASS4_SETTINGSCOMMAND_H
#define ASS4_SETTINGSCOMMAND_H
#include "General/Command.h"
#include "General/Database.h"
#include "ServerCLI/util.h"

class SettingsCommand : public  Command {
    Database *database;
public:
    SettingsCommand(DefaultIO *pIo, Database *pDatabase);
    ~SettingsCommand() override = default;
    void execute() override;
};



#endif //ASS4_SETTINGSCOMMAND_H
