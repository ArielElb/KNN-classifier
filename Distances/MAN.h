#ifndef ASS3_MAN_H
#define ASS3_MAN_H

#include "General/Vector.h"
#include "Distances/Distances.h"

class MAN : public Distances {
public:
    MAN();  // Constructor
    ~MAN() ; // Destructor
    // Destructor
    void operator()(Vector &a, Vector &b) override;
};
#endif //ASS3_MAN_H
