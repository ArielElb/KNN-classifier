//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SOCKETIO_H
#define ASS4_SOCKETIO_H

#include <string>
#include "DefaultIO.h"

class SocketIO : public DefaultIO {
    // bindSocket , listen , accept , read , write , close - methods
    std::string read() override;
    void write(std::string string) override;
    virtual  int bindSocket(int port) = 0;
    SocketIO() = default;
    virtual ~SocketIO() = default;



};


#endif //ASS4_SOCKETIO_H
