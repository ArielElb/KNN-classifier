#include <thread>
#include "ClientCLI/DownloadFile.h"
#include "General/Client.h"

/*
 * Download command (option 5). If error message received quit. Else, read port number from server and open thread
 * to read from corresponding socket.
 */
void DownloadFile::execute() {
    std::string fromServer;
    try {
        fromServer = this->dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket." << std::endl;
        return;
    }
    // acknowledge
    // Handle message from server
    bool err = false;
    if (fromServer == "please upload data\nplease classify the data\n") {
        err = true;
    }
    if (fromServer == "please classify the data\n") {
        err = true;
    }
    if (fromServer == "please upload data\n") {
        return;
    }
    this->dio->write("0");
    if (err) {
       std::cout << fromServer << std::endl;
       return;
    }
    std::cout << "Please enter a path to save the classifications" << std::endl;
    std::string path;
    std::getline(std::cin, path);
    // fromServer contains new port number for communication
    unsigned short newPort;
    try {
        newPort = std::stoi(fromServer);
    } catch (...) {
        std::cerr << "Received unexpected input from server." << std::endl;
        return;
    }
    int sockfd;
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
