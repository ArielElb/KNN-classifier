#ifndef ASS4_UPLOADCOMMAND_H
#define ASS4_UPLOADCOMMAND_H
#include "General/Command.h"
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
