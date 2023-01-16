#include "CHB.h"

void CHB::operator()(Vector &a, Vector &target) {
    Vector absDiff;
    absDiff.init(a.absValueDiff(target));
    a.setDistFromArg(Vector::chebyshevDistance(absDiff));
}
CHB::CHB() = default;
CHB::~CHB() = default;
