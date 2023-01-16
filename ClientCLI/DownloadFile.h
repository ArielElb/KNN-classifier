//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_DOWNLOADFILE_H
#define ASS4_DOWNLOADFILE_H

#include "Command.h"
#include "IO/DefaultIO.h"

class DownloadFile : public Command {
public:
    void execute() override;

    virtual ~DownloadFile() = default;

    DownloadFile(DefaultIO *socketIO, DefaultIO *file);

private:
    DefaultIO *fileIO;
};


#endif //ASS4_DOWNLOADFILE_H
