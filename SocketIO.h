#ifndef ASS4_SOCKETIO_H
#define ASS4_SOCKETIO_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include "DefaultIO.h"

class SocketIO : public DefaultIO {
    int sockfd;
    // bindSocket , listen , accept , read , write , close - methods
public:
    /*
     * HOW TO USE - read():
     * Always wrap call to read() in try catch statement as such"
     * SocketIO sio(socketfd);
     * try {
     *     sio.read();    
     * } catch (std::ios_base::failure const &ex) {
     *     // This exception indicates failure reading from socket
     *     Handle error here
     * } catch (std::out_of_range const &ex) {
     *     // This exception indicates communication was disconnected by other party
     *     Handle behavior here
     * }
     */
    std::string read() override;
    int write(std::string string) override;

    explicit SocketIO(int sockfd) {
        this->sockfd = sockfd;
    }
    ~SocketIO() = default;
};


#endif //ASS4_SOCKETIO_H
