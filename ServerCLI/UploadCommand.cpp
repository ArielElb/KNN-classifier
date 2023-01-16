//
// Created by arie1 on 1/14/2023.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio, Database *database) {
    this->dio = dio;
}

void UploadCommand::execute() {
    std::string fileContent;
    this->database = new Database();
    // upload a data file to the server
    dio->write("Please upload your local train CSV file.\n");

    try {
        fileContent = dio->read();
        if (fileContent == "invalid input") {
            return;
        }
        this->database->initTrainVectors(fileContent);
    }
    catch (std::ios_base::failure const &ex) {
    }
    dio->write("Please upload your local test CSV file.\n");
    try {
        fileContent = dio->read();
        if (fileContent == "invalid input") {
            return;
        }
        this->database->initTestVectors(fileContent);
    }
    catch (std::ios_base::failure const &ex) {

    }
}
