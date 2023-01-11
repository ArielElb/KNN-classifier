#include "Comparator.h"
/**
 * Compare two vectors by their distance from the argument vector
 * @param a - vector1
 * @param b - vector2
 * @return - true if a is closer to the argument vector than b
 */
bool Comparator::operator()(const Vector &a,const Vector &b) {
    // Compare two vectors by distFromArg
    return a.getDistFromArg() < b.getDistFromArg();
}