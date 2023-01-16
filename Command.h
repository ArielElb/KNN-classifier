#ifndef ASS4_COMMAND_H
#define ASS4_COMMAND_H


#include "DefaultIO.h"

class Command {
protected:
    DefaultIO *dio{};
    std::string description;
public:
    virtual void execute() = 0;
    DefaultIO *getDio() const;
};

DefaultIO *Command::getDio() const {
    return dio;
}

#endif
