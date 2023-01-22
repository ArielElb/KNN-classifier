#include "ClientCLI/Downloader.h"

void Downloader::operator()(DefaultIO *socket, DefaultIO *file) {
    std::string classifications;
    try{
        classifications = socket->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
    }
    file->write(classifications);
}
