//
// Created by arie1 on 1/16/2023.
//

#ifndef ASS4_DOWNLOADFILE_H
#define ASS4_DOWNLOADFILE_H
#include "Command.h"
#include "IO/DefaultIO.h"

class DownloadFile : public Command {
    public:
        explicit DownloadFile(DefaultIO* dio);
        void execute() override;
        virtual ~DownloadFile() = default;

    DefaultIO *dio;
};


#endif //ASS4_DOWNLOADFILE_H
