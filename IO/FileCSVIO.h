//
// Created by arie1 on 1/15/2023.
//

#ifndef ASS4_FILECSVIO_H
#define ASS4_FILECSVIO_H

#include "DefaultIO.h"

class FileCSVIO : public DefaultIO {

//    void write(std::string text) override;

    std::string read() override;

    void print(std::string text);

public:
    FileCSVIO(std::string path);
};


#endif //ASS4_FILECSVIO_H
