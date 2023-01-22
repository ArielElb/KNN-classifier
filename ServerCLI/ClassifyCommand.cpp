#include "ServerCLI/ClassifyCommand.h"

void ClassifyCommand::execute() {
    if (database->isFilesUnloaded()) {
        dio->write("please upload data\n");
        try {
            dio->read();
        } catch (...) {
            std::cerr << "Error reading from client." << std::endl;
            return;
        }
        // approval from client
        try {
            dio->read();
        }
        catch (...) {
            std::cerr << "Error reading from client." << std::endl;
            return;
        }
        return;
    }
    if (database->getKInt() > database->size()) {
        database->setK(database->size());
    }
    std::string returnstr = "classifying data complete\n";
    try {
        database->knn();
    } catch (...) {
        returnstr = "Found errors in one or more files. Please upload new files and try again.\n";
    }
    dio->write(returnstr);
    // approval from client
    try {
        dio->read();
    } catch (...) {
        std::cerr << "Error reading from client." << std::endl;
        return;
    }
}

ClassifyCommand::ClassifyCommand(DefaultIO *pIo, Database *pDatabase) {
    dio = pIo;
    database = pDatabase;
}

