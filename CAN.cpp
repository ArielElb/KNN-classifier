#include "CAN.h"

void CAN::operator()(Vector &a, Vector &b) {
    Vector absDiff;
    absDiff.init(a.absValueDiff(b));
    a.setDistFromArg(a.canberraDistance(a,b));
}
CAN::CAN() = default;
CAN::~CAN() = default;
