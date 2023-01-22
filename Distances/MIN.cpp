#include "Distances/MIN.h"

void MIN::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    try {
        absDiff.init(a.absValueDiff(b));
    } catch (...) {
        throw;
    }
    a.setDistFromArg(Vector::minkowskiDistance(absDiff));
}
MIN::MIN() = default;
MIN::~MIN() = default;

