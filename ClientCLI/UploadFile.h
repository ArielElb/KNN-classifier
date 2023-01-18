//
// Created by arie1 on 1/17/2023.
//

#ifndef ASS4_UPLOADFILE_H
#define ASS4_UPLOADFILE_H
#include "Command.h"
#include <chrono>

class UploadFile : public Command {
    void execute() override;
    DefaultIO* fileIO = nullptr;
    virtual ~UploadFile() = default;

public :
    explicit UploadFile(DefaultIO *socketIO);
};


#endif //ASS4_UPLOADFILE_H
