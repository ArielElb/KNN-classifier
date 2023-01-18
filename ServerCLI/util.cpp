#include "util.h"

bool checkDistanceFunc(std::string &distance) {
    if (distance == "MAN" || distance == "AUC" || distance == "CHE" || distance == "MIN"
        || distance == "CHB") {
        return true;
    }
    return false;
}