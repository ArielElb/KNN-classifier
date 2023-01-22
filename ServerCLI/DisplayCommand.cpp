#include "ServerCLI/DisplayCommand.h"

void DisplayCommand::execute() {
    // display the data file that is already uploaded to the server
    if (database->isFilesUnloaded() && database->getClassfications() == "") {
        dio->write("please upload data\nplease classify the data\n");
        try {
            dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket." << std::endl;
        }
        return;
    }
    else if (database->getClassfications().empty()) {
        dio->write("please classify the data\n");
        try {
            dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket." << std::endl;
        }
        return;
    }
    else if (database->isFilesUnloaded()) {
        dio->write("please upload data\n");
        try {
            dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket." << std::endl;
        }
        return;
    }
    dio->write(database->getClassfications() + "Done.");
    std::string fromClient;
    try {
        fromClient = dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket." << std::endl;
    }
}

DisplayCommand::DisplayCommand(DefaultIO *pIo, Database *pDatabase) {
    dio = pIo;
    database = pDatabase;
}


