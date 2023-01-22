#ifndef ASS3_MIN_H
#define ASS3_MIN_H

#include "General/Vector.h"
#include "Distances/Distances.h"

class MIN : public Distances {
public:
    void operator()(Vector &a, Vector &b) override;
    MIN();  // Constructor
    ~MIN() ; // Destructor
};
#endif //ASS3_MIN_H
