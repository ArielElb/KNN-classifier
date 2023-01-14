//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_CLASSIFYCOMMAND_H
#define ASS4_CLASSIFYCOMMAND_H


#include "Command.h"

class ClassifyCommand : public  Command {
    void execute() override;

    virtual ~ClassifyCommand() = default;

public:
//constractor
ClassifyCommand() = default;
};




#endif //ASS4_CLASSIFYCOMMAND_H
