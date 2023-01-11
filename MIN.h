#ifndef ASS3_MIN_H
#define ASS3_MIN_H

#include "Vector.h"
#include "Distances.h"

class MIN : public Distances {
public:
    void operator()(Vector &a, Vector &b) override;
    MIN();  // Constructor
    ~MIN() ; // Destructor
};
#endif //ASS3_MIN_H
