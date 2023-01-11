#ifndef ASS3_AUC_H
#define ASS3_AUC_H
#include "Vector.h"
#include "Distances.h"

class AUC : public Distances {
    public:
    void operator()(Vector &a, Vector &b) override;
    AUC();  // Constructor
    ~AUC() ; // Destructor
};
#endif //ASS3_AUC_H
