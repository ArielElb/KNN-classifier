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
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        return;
    }
    std::string returnstr = "classifying data complete\n";
    try {
        database->knn();
    } catch (...) {
        returnstr = "Found errors in one or more files. Please upload new files and try again.\n";
    }
    //thread sleep for 1 sec
    dio->write(returnstr);
    try {
        dio->read();
    } catch (...) {
        std::cerr << "Error reading from client." << std::endl;
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

}

ClassifyCommand::ClassifyCommand(DefaultIO *pIo, Database *pDatabase) {
    dio = pIo;
    database = pDatabase;
}

