#ifndef ASS4_UPLOADFILE_H
#define ASS4_UPLOADFILE_H
#include "General/Command.h"
class UploadFile : public Command {
    void execute() override;
    DefaultIO* fileIO = nullptr;
    virtual ~UploadFile() = default;

public :
    explicit UploadFile(DefaultIO *socketIO);
};


#endif //ASS4_UPLOADFILE_H
