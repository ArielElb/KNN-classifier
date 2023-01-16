//
// Created by arie1 on 1/14/2023.
//

#include "DownloadCommand.h"

void DownloadCommand::execute() {
    // download a data file from the server


}
DownloadCommand::DownloadCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}