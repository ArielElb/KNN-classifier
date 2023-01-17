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
    /*
     * returns entire content of file in one string
     */
    std::string read();
    /*
     * Write string as a new line at the end of the file
     */
    int write(std::string text);
};


#endif //ASS4_FILEIO_H
