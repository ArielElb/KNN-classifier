#ifndef ASS4_CLASSIFYCOMMAND_H
#define ASS4_CLASSIFYCOMMAND_H

#include "General/Command.h"
#include <thread>
class ClassifyCommand : public  Command {
    void execute() override;

    virtual ~ClassifyCommand() = default;

public:
//constractor
    ClassifyCommand(DefaultIO *pIo, Database *pDatabase);
    Database *database;
    DefaultIO *dio;
};

#endif //ASS4_CLASSIFYCOMMAND_H
