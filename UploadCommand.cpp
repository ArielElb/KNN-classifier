//
// Created by arie1 on 1/14/2023.
//

#include "UploadCommand.h"

void UploadCommand::execute() {
    dio->write("Please upload your local train CSV file.\n");
    /// data is t
    std::string fileContent = dio->read();
    try {
        this->database = new Database(fileContent);
        this->database->init();

        dio->write("Upload complete.\n");
    } catch (const std::exception& e) {
        dio->write("invalid input\n");
        return;
    }

    // upload an unclassified csv file data file to the server
    // the file will be classified by the server
}
UploadCommand::UploadCommand(DefaultIO *dio, Database *database) {
    this->dio = dio;
}
