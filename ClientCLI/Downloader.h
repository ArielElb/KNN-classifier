#ifndef ASS4_DOWNLOADER_H
#define ASS4_DOWNLOADER_H
#include "IO/SocketIO.h"
#include "IO/FileIO.h"

class Downloader {
public:
    Downloader() = default;
    virtual ~Downloader() = default;
    void operator()(DefaultIO *socket, DefaultIO *file);
};

#endif //ASS4_DOWNLOADER_H
