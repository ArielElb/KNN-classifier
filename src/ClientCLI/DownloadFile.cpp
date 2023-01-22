#include <thread>
#include "ClientCLI/DownloadFile.h"
#include "General/Client.h"

void DownloadFile::execute() {
    std::string fromServer = this->dio->read();
    this->dio->write("0");
    // acknowledge
    // Handle message from server
    if (fromServer == "please upload data\nplease classify the data\n") {
        return;
    }
    if (fromServer == "please classify the data\n") {
        return;
    }
    if (fromServer == "please upload data\n") {
        return;
    }
    std::cout << "Please enter a path to save the classifications" << std::endl;
    std::string path;
    std::getline(std::cin, path);
    // fromServer contains new port number for communication
    unsigned short newPort = std::stoi(fromServer);
    int sockfd;
    std::cout << "Connecting to port " << newPort << std::endl;
    try {
        sockfd = Client::connectSock(newPort);
    } catch (std::ios_base::failure const &ex) {
        std::cerr << ex.what() << std::endl;
        throw ex;
    }
    SocketIO *socket = new SocketIO(sockfd);
    FileIO *file = new FileIO(path);
    Downloader d;
    std::thread thread1(d, socket, file);
    thread1.detach();
}

DownloadFile::DownloadFile(DefaultIO *socketIO) {
    this->dio = socketIO;
}
