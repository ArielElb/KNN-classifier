#include "Comparator.h"
/**
 * Compare two trainVectors by their distance from the argument vector
 * @param a - vector1
 * @param b - vector2
 * @return - true if a is closer to the argument vector than b
 */
bool Comparator::operator()(const Vector &a,const Vector &b) {
    // Compare two trainVectors by distFromArg
    return a.getDistFromArg() < b.getDistFromArg();
}