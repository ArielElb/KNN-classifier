#include "ClientCLI/Downloader.h"

/*
 * Functor for downloading classification files from server. Reads from socket then writes to file
 * @param socket
 * @param file
 */
void Downloader::operator()(DefaultIO *socket, DefaultIO *file) {
    std::string classifications;
    try{
        classifications = socket->read();
    } catch (...) {
        std::cerr << "Error reading from socket" << std::endl;
    }
    file->write(classifications);
}
