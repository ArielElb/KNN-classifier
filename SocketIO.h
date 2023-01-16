#ifndef ASS4_SOCKETIO_H
#define ASS4_SOCKETIO_H

#include <string>
#include "DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketIO : public DefaultIO {
    // bindSocket , listen , accept , read , write , close - methods
    int sockfd;
public:
    std::string read() override;
    int write(std::string string) override;
    explicit SocketIO(int sockfd) {
        this->sockfd = sockfd;
    }
    virtual ~SocketIO() = default;
};


#endif //ASS4_SOCKETIO_H
