#include "ServerCLI/DisplayCommand.h"

void DisplayCommand::execute() {
    // display the data file that is already uploaded to the server
    if (database->isFilesUnloaded() && database->getClassfications() == "") {
        this->dio->write("please upload data\nplease classify the data\n");
        this->dio->read();
        return;
    }
    else if (this->database->getClassfications().empty()) {
        this->dio->write("please classify the data\n");
        this->dio->read();
        return;
    }
    else if (database->isFilesUnloaded()) {
        this->dio->write("please upload data\n");
        this->dio->read();
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


