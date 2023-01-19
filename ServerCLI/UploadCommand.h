//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_UPLOADCOMMAND_H
#define ASS4_UPLOADCOMMAND_H
#include "Command.h"
#include <thread>


class UploadCommand : public  Command {
    DefaultIO *dio;
    Database *database{};
public:
    UploadCommand(DefaultIO *dio, Database *database);
    void execute() override;
    ~UploadCommand() override = default;
};
#endif //ASS4_UPLOADCOMMAND_H
