#include "ClientCLI/Downloader.h"

void Downloader::operator()(DefaultIO *socket, DefaultIO *file) {
    std::cout << "entered thread" << std::endl;
    std::string classifications;
    try{
        std::cout << "SDFSDF" << std::endl;
        classifications = socket->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
    }
    std::cout << "abut to write to file" << std::endl;
    file->write(classifications);
    std::cout << "done writing to file" << std::endl;
    socket->write("done reading");
}
