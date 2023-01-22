#include "Distances/CHB.h"

void CHB::operator()(Vector &a, Vector &target) {
    Vector absDiff;
    try {
        absDiff.init(a.absValueDiff(target));
    } catch (...) {
        throw;
    }
    a.setDistFromArg(Vector::chebyshevDistance(absDiff));
}
CHB::CHB() = default;
CHB::~CHB() = default;
