//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_DISPLAYCOMMAND_H
#define ASS4_DISPLAYCOMMAND_H
#include "Command.h"

class DisplayCommand : public  Command {
    void execute() override;

    virtual ~DisplayCommand() = default;

public:
//constractor
DisplayCommand() = default;
};


#endif //ASS4_DISPLAYCOMMAND_H
