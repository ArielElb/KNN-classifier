#include "Uploader.h"

void Uploader::operator()(DefaultIO *socket, Database *database) {
    socket->write(database->getClassfications());
    std::cout << "done writing to socket" << std::endl;
}