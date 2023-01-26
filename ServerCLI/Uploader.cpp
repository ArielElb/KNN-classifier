#include "Uploader.h"

/**
 * Uploader functor for multithreaded file sending
 * @param socket socketIO for writing
 * @param database database to get classification from
 */
void Uploader::operator()(DefaultIO *socket, Database *database) {
    socket->write(database->getClassfications());
}