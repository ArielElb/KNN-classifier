//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_STANDARDIO_H
#define ASS4_STANDARDIO_H

#include "DefaultIO.h"
#include "iostream"
class StandardIO : public DefaultIO {
    public:
    std::string read() override;
    void write(std::string text) override;

    // read a line from the user
    // write a line to the user


};


#endif //ASS4_STANDARDIO_H
