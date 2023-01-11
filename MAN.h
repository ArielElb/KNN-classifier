#ifndef ASS3_MAN_H
#define ASS3_MAN_H

#include "Vector.h"
#include "Distances.h"

class MAN : public Distances {
public:
    MAN();  // Constructor
    ~MAN() ; // Destructor
    // Destructor
    void operator()(Vector &a, Vector &b) override;
};
#endif //ASS3_MAN_H
