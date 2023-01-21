#include "ServerCLI/DownloadCommand.h"

void DownloadCommand::execute() {
   if (database->isFilesUnloaded() && database->getClassfications() == "") {
        this->dio->write("please upload data\nplease classify the data\n");
        this->dio->read();
        return;
    }
    if (this->database->getClassfications().empty()) {
        this->dio->write("please classify the data\n");
        this->dio->read();
        return;
    }
    if (database->isFilesUnloaded()) {
        this->dio->write("please upload data\n");
        this->dio->read();
        return;
    }
    this->dio->write(database->getClassfications());
    std::string fromClient = this->dio->read();
    std::cout << fromClient << std::endl;   // download a data file from the server
}
DownloadCommand::DownloadCommand(DefaultIO *pIo, Database *pDatabase) {
    this->dio = pIo;
    this->database = pDatabase;
}