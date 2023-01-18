//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SERVERCLI_H
#define ASS4_SERVERCLI_H

#include "UploadCommand.h"
#include "Command.h"
#include "SettingsCommand.h"
#include "ClassifyCommand.h"
#include "DisplayCommand.h"
#include "DownloadCommand.h"
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
