//
// Created by arie1 on 1/15/2023.
//

#ifndef ASS4_FILECSVIO_H
#define ASS4_FILECSVIO_H
#include "DefaultIO.h"

class FileCSVIO : public DefaultIO {
    int openFile();
    int closeFile();
    std::string read();
    void write();
};


#endif //ASS4_FILECSVIO_H
