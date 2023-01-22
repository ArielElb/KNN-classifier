#include "Distances/AUC.h"

void AUC::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    try {
        absDiff.init(a.absValueDiff(b));
    } catch (...) {
        throw;
    }
    a.setDistFromArg(Vector::euclideanDistance(absDiff));
}
AUC::AUC() = default;
AUC::~AUC() = default;