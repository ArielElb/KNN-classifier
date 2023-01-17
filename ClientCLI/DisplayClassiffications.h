//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_DISPLAYCLASSIFFICATIONS_H
#define ASS4_DISPLAYCLASSIFFICATIONS_H
#include "Command.h"
#include "IO/DefaultIO.h"

class DisplayClassiffications : public Command {
    //void execute() override;
    void execute() override;
    virtual ~DisplayClassiffications() = default;

public:
    explicit DisplayClassiffications(DefaultIO *dio);
};


#endif //ASS4_DISPLAYCLASSIFFICATIONS_H
