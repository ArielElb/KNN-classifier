#include "ServerCLI/DownloadCommand.h"
#include <unistd.h>
#include <sys/socket.h>
#include <thread>
#include "General/Server.h"
#include "ServerCLI/Uploader.h"

/*
 * Runs server side of download command (option 5).
 * Binds to an available socket, send port address to client, then opens a thread to handle sending the file over the
 * new socket.
 */
void DownloadCommand::execute() {
    if (database->isFilesUnloaded() && database->getClassfications() == "") {
        this->dio->write("please upload data\nplease classify the data\n");
        try {
            this->dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket" << std::endl;
        }
        return;
    }
    if (database->getClassfications().empty()) {
        this->dio->write("please classify the data\n");
        try {
            this->dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket" << std::endl;
        }
        return;
    }
    if (database->isFilesUnloaded()) {
        this->dio->write("please upload data\n");
        try {
            this->dio->read();
        } catch (...) {
            std::cerr << "Error reading from socket" << std::endl;
        }
        return;
    }
    // if all is good, bind to port
    int newSock = Server::bindSock(0);
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    if (getsockname(newSock, (struct sockaddr *)(&addr), &addrlen) < 0) {
        std::cerr << "Error starting new socket" << std::endl;
        return;
    }
    // send port number to client
    unsigned short port = ntohs(addr.sin_port);
    this->dio->write(std::to_string(port));
    try {
        this->dio->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
    }
    if (listen(newSock, 1) < 0) {
        throw std::ios_base::failure("Error listening to a socket");
    }
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    int clientSock = accept(newSock, (struct sockaddr *)&client_sin, &addr_len);
    if (clientSock < -1) {
        throw std::ios_base::failure("Error accepting client");
    }
    // open socketIO for new thread to write to
    SocketIO *socket = new SocketIO(clientSock);
    Uploader u;
    std::thread thread1(u, socket, this->database);
    thread1.detach();
}

DownloadCommand::DownloadCommand(DefaultIO *pIo, Database *pDatabase) {
    dio = pIo;
    database = pDatabase;
}