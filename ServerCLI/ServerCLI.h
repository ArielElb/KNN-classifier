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
#include "IO/DefaultIO.h"
#include "Database.h"

class ServerCLI {
public:
    explicit ServerCLI(DefaultIO *dio);
    virtual ~ServerCLI();
    void start();
private:
    Database *database{};
    DefaultIO *dio;
    std::vector<Command *> commands;
    void initCommands();
};

#endif //ASS4_SERVERCLI_H
