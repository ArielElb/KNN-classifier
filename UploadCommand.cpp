//
// Created by arie1 on 1/14/2023.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio, Database *database) {
    this->dio = dio;
}

void UploadCommand::execute() {
    this->database = new Database();
    // upload a data file to the server
    dio->write("Please upload your local train CSV file.\n");
    /// data is t
    std::string fileContent = dio->read();
    try {
        this->database->initTrainVectors(fileContent);
    }
    catch (std::ios_base::failure const &ex) {
    }
    dio->write("Please upload your local test CSV file.\n");
    try {
        this->database->initTestVectors(fileContent);
    }
    catch (std::ios_base::failure const &ex) {
    }
}
