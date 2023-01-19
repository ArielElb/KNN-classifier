//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_DOWNLOADCOMMAND_H
#define ASS4_DOWNLOADCOMMAND_H
#include "Command.h"

class DownloadCommand :public  Command {
    void execute() override;

    Database *database;
public:
//constractor
    DownloadCommand(DefaultIO *pIo, Database *pDatabase);
    ~DownloadCommand() override = default;
};



#endif //ASS4_DOWNLOADCOMMAND_H
