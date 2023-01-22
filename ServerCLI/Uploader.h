#ifndef ASS4_UPLOADER_H
#define ASS4_UPLOADER_H

#include "IO/SocketIO.h"
#include "IO/FileIO.h"
#include "General/Database.h"

class Uploader {
public:
    Uploader() = default;
    virtual ~Uploader() = default;
    void operator()(DefaultIO *socket, Database *database);
};


#endif //ASS4_UPLOADER_H
