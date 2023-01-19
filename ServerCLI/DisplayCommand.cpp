//
// Created by arie1 on 1/14/2023.
//

#include "DisplayCommand.h"

void DisplayCommand::execute() {
    // display the data file that is already uploaded to the server
    if (database->isFilesUnloaded() && database->getClassfications() == "") {
        this->dio->write("please upload data\nplease classify the data\n");
        return;
    }
    else if (this->database->getClassfications() == "") {
        this->dio->write("please classify the data\n");
        return;
    }
    else if (database->isFilesUnloaded()) {
        this->dio->write("please upload data\n");
        return;
    }
    this->dio->write(database->getClassfications() + "Done.");
    std::string fromClient = this->dio->read();
    std::cout << fromClient << std::endl;
}

DisplayCommand::DisplayCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}


