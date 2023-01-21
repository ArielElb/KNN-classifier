#ifndef ASS3_CAN_H
#define ASS3_CAN_H

#include "General/Vector.h"
#include "Distances/Distances.h"

class CAN : public Distances {
    public:
    void operator()(Vector &a, Vector &b) override;
    CAN();  // Constructor
    ~CAN(); // Destructor
};
#endif //ASS3_CAN_H
