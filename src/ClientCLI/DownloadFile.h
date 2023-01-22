#ifndef ASS4_DOWNLOADFILE_H
#define ASS4_DOWNLOADFILE_H

#include "General/Command.h"
#include "IO/DefaultIO.h"
#include <filesystem>
#include "ClientCLI/Downloader.h"

class DownloadFile : public Command {
    DefaultIO *fileIO{};
public:
    void execute() override;
    ~DownloadFile() override = default;
    explicit DownloadFile(DefaultIO *socketIO);
};


#endif //ASS4_DOWNLOADFILE_H
