#ifndef ASS3_COMPARATOR_H
#define ASS3_COMPARATOR_H

#include "Vector.h"
/*
 * Comparator functor class
 */
class Comparator {
public:
    bool operator()(const Vector &a,const Vector &b);
};
#endif //ASS3_COMPARATOR_H
