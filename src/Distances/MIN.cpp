#include "Distances/MIN.h"

void MIN::operator()(Vector &a, Vector &b) {

    Vector absDiff;
    absDiff.init(a.absValueDiff(b));
    a.setDistFromArg(Vector::minkowskiDistance(absDiff));
}
MIN::MIN() = default;
MIN::~MIN() = default;

