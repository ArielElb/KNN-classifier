#ifndef ASS4_SERVERCLI_H
#define ASS4_SERVERCLI_H

#include "ServerCLI/UploadCommand.h"
#include "General/Command.h"
#include "ServerCLI/SettingsCommand.h"
#include "ServerCLI/ClassifyCommand.h"
#include "ServerCLI/DisplayCommand.h"
#include "ServerCLI/DownloadCommand.h"
#include <vector>


class ServerCLI {
public:
    ServerCLI(DefaultIO *dio);
    virtual ~ServerCLI();
    void start();
private:
    Database *database = new Database();
    std::vector<Command *> commands = {};
    void initCommands();
    DefaultIO *dio = nullptr;
};

#endif //ASS4_SERVERCLI_H
