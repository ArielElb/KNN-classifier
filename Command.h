#ifndef ASS4_COMMAND_H
#define ASS4_COMMAND_H

#include "IO/DefaultIO.h"

class Command {
protected:
    DefaultIO *dio{};
    std::string description;
public:
    virtual void execute() = 0;
};


#endif
