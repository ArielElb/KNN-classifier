#ifndef ASS3_DISTANCES_H
#define ASS3_DISTANCES_H

#include "Vector.h"

class Distances {
// Virtual implementation of distance functor
public:
    Distances() = default;
    virtual ~Distances() = default;
    virtual void operator()(Vector &a, Vector &b) = 0;
};
#endif //ASS3_DISTANCES_H
