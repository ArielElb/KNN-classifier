#ifndef ASS4_DOWNLOADCOMMAND_H
#define ASS4_DOWNLOADCOMMAND_H
#include "General/Command.h"

class DownloadCommand :public  Command {
    void execute() override;

    Database *database;
public:
    DownloadCommand(DefaultIO *pIo, Database *pDatabase);
    ~DownloadCommand() override = default;
};

#endif //ASS4_DOWNLOADCOMMAND_H
