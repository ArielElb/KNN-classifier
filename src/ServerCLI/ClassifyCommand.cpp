#include "ServerCLI/ClassifyCommand.h"

void ClassifyCommand::execute() {
    if (database->isFilesUnloaded()) {
        this->dio->write("please upload data\n");
        this->dio->read();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        return;
    }
    this->database->knn();
    //thread sleep for 1 sec
    this->dio->write("classifying data complete\n");
    this->dio->read();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

}

ClassifyCommand::ClassifyCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}

