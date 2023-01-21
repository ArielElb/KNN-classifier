#include <thread>
#include "ClientCLI/DownloadFile.h"

void DownloadFile::execute() {
//    std::cout << "Please enter a path to save the classifications" << std::endl;
    std::string path;
    std::cin.ignore();
    std::getline(std::cin, path);
    std::string fromServer = this->dio->read();
    std::cout << fromServer ;
    if (fromServer == "please upload data\nplease classify the data\n") {
        this->dio->write("1");
        return;
    }
    if (fromServer == "please classify the data\n") {
        this->dio->write("1");
        return;
    }
    if (fromServer == "please upload data\n") {
        this->dio->write("1");
        return;
    }
    FileIO *file = new FileIO(path);
    Downloader d;
    std::thread thread1(d, this->dio, file);
}

DownloadFile::DownloadFile(DefaultIO *socketIO) {
    this->dio = socketIO;
}
