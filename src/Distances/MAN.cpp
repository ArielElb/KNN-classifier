#include "Distances/MAN.h"

void MAN::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    try {
        absDiff.init(a.absValueDiff(b));
    } catch (...) {
        throw;
    }
    a.setDistFromArg(Vector::manhattanDistance(absDiff));
}

MAN::MAN() = default;
MAN::~MAN() = default;