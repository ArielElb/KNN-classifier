//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_DISPLAYCOMMAND_H
#define ASS4_DISPLAYCOMMAND_H
#include "Command.h"
#include "DefaultIO.h"
#include "Database.h"

class DisplayCommand : public  Command {
    void execute() override;
    Database *database;
    DefaultIO *dio;
    virtual ~DisplayCommand() = default;

public:
//constractor
    DisplayCommand(DefaultIO *pIo, Database *pDatabase);
};


#endif //ASS4_DISPLAYCOMMAND_H
