#include "Uploader.h"

void Uploader::operator()(DefaultIO *socket, Database *database) {
    socket->write(database->getClassfications());
}