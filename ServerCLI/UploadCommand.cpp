//
// Created by arie1 on 1/14/2023.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio, Database *database) {
    this->dio = dio;
    this->database = database;
}

void UploadCommand::execute() {
    this->database->resetFiles();
    std::string fileContent;
    // upload a data file to the server
    dio->write("Please upload your local train CSV file.\n");
    try {
        fileContent = dio->read();
        if (fileContent == "invalid input") {
            return;
        }
        this->database->initTrainVectors(fileContent);
        dio->write("Upload complete.\nPlease upload your local test CSV file.\n");
    }
    catch (std::ios_base::failure const &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    try {
        fileContent = dio->read();
        if (fileContent == "invalid input") {
            return;
        }
        this->database->initTestVectors(fileContent);
        this->dio->write("Upload complete.\n");
        // wait for the server to finish the upload - sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    catch (std::ios_base::failure const &ex) {
        throw;
    }
}
