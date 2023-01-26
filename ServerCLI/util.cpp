#include "ServerCLI/util.h"

/**
 * Checks if distance func is valid
 * @param distance string repr of distance function
 * @return true if valid false otherwise
 */
bool checkDistanceFunc(std::string &distance) {
    if (distance == "MAN" || distance == "AUC" || distance == "CHE" || distance == "MIN"
        || distance == "CHB") {
        return true;
    }
    return false;
}