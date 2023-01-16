//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_UPLOADCOMMAND_H
#define ASS4_UPLOADCOMMAND_H
#include "Command.h"
#include "DefaultIO.h"
#include "Database.h"

class UploadCommand : public  Command {
    void execute() override;\
    virtual ~UploadCommand();

public:
//constractor
UploadCommand(DefaultIO *dio, Database *database);
    DefaultIO *dio;
    Database *database{};
};
#endif //ASS4_UPLOADCOMMAND_H
