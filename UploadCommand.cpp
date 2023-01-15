//
// Created by arie1 on 1/14/2023.
//

#include "UploadCommand.h"

void UploadCommand::execute() {
    std::string data = dio->read();
    const std::string& fileName = data;
    this-> database =  new Database(fileName);
    this-> database->init();

    // upload an unclassified csv file data file to the server
    // the file will be classified by the server
}
UploadCommand::UploadCommand(DefaultIO *dio, Database *database) {
    this->dio = dio;
}
