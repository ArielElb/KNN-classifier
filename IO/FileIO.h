//
// Created by arie1 on 1/15/2023.
//

#ifndef ASS4_FILEIO_H
#define ASS4_FILEIO_H

#include "DefaultIO.h"
#include <fstream>
#include <iostream>

class FileIO : public DefaultIO {
    std::string path;
public:
    FileIO(std::string path);
    std::string read();
    int write(std::string text);
};


#endif //ASS4_FILEIO_H
