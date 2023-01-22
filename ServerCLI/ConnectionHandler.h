#ifndef ASS4_CONNECTIONHANDLER_H
#define ASS4_CONNECTIONHANDLER_H

#include "IO/DefaultIO.h"

class ConnectionHandler {
public:
    ConnectionHandler() = default;
    virtual ~ConnectionHandler() = default;
    void operator()(DefaultIO *);

};
#endif //ASS4_CONNECTIONHANDLER_H
