#include "Distances/CAN.h"

void CAN::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    try {
        absDiff.init(a.absValueDiff(b));
    } catch (...) {
        throw;
    }
    a.setDistFromArg(a.canberraDistance(a,b));
}
CAN::CAN() = default;
CAN::~CAN() = default;
