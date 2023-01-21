#include "Distances/MAN.h"

void MAN::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    absDiff.init(a.absValueDiff(b));
    a.setDistFromArg(Vector::manhattanDistance(absDiff));
}

MAN::MAN() = default;
MAN::~MAN() = default;