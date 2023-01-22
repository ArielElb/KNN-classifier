#ifndef ASS4_COMMAND_H
#define ASS4_COMMAND_H

#include "IO/DefaultIO.h"
#include "Database.h"
#include "IO/FileIO.h"

class Command {
protected:
    std::string description;
public:
    DefaultIO *dio{};
    virtual void execute() = 0;
    virtual ~Command() = default;
};

#endif
