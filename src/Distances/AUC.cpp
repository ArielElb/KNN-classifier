#include "Distances/AUC.h"

void AUC::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    absDiff.init(a.absValueDiff(b));
    a.setDistFromArg(Vector::euclideanDistance(absDiff));
}
AUC::AUC() = default;
AUC::~AUC() = default;