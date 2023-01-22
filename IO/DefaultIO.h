#ifndef ASS4_DEFAULTIO_H
#define ASS4_DEFAULTIO_H
#include <string>
class DefaultIO {
public:
    virtual int write(std::string text) = 0;
    virtual std::string read() = 0;
    virtual ~DefaultIO() = default;
};


#endif //ASS4_DEFAULTIO_H
