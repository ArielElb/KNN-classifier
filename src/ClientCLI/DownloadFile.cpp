#include <thread>
#include "ClientCLI/DownloadFile.h"
#include "General/Client.h"

void DownloadFile::execute() {
    std::cout << "Please enter a path to save the classifications" << std::endl;
    std::string path;
    std::cin.ignore();
    std::getline(std::cin, path);
    std::string fromServer = this->dio->read();
    // acknowledge
    this->dio->write("1");
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
    // fromServer contains new port number for communication
    std::cout << "Connecting to port " << fromServer << std::endl;
    int sockfd;
    try {
        sockfd = Client::connectSock((unsigned short) std::stoi(fromServer));
    } catch (std::ios_base::failure const &ex) {
        std::cerr << ex.what() << std::endl;
        throw ex;
    }
    std::cout << "Spawning downloader thread" << std::endl;
    SocketIO *socket = new SocketIO(sockfd);
    FileIO *file = new FileIO(path);
    Downloader d;
    std::thread thread1(d, socket, file);
    thread1.detach();
    std::cout << "opened thread, returning to menu" << std::endl;
}

DownloadFile::DownloadFile(DefaultIO *socketIO) {
    this->dio = socketIO;
}
