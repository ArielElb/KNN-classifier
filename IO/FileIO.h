#ifndef ASS4_FILEIO_H
#define ASS4_FILEIO_H

#include "IO/DefaultIO.h"
#include <fstream>
#include <iostream>

class FileIO : public DefaultIO {
    std::string path;
public:
    explicit FileIO(std::string path);

    FileIO();

    /*
     * returns entire content of file in one string
     */
    std::string read() override;
    /*
     * Write string as a new line at the end of the file
     */
    int write(std::string text) override;
};


#endif //ASS4_FILEIO_H
