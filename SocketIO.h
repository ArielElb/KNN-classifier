//
// Created by arie1 on 1/14/2023.
//

#ifndef ASS4_SOCKETIO_H
#define ASS4_SOCKETIO_H

#include <string>
class SocketIO {
    // bindSocket , listen , accept , read , write , close - methods
    virtual  void send(const std::string& data) = 0;
    virtual  int connect() = 0;
    virtual  std::string receive() = 0;
    virtual  int bindSocket(int port) = 0;
    virtual  ~SocketIO() = default;



};


#endif //ASS4_SOCKETIO_H
