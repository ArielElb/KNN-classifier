#include "Database.h"
#include <algorithm>
#include <map>

using std::string;
using std::vector;

/**
 * Constructor.
 * @param s file name
 * @param k k nearest
 */
Database::Database(const string &s) {
    // Create string vector for class parameter
    this->fileContent = s;
    this->distance = nullptr;
}


/**
 * @brief init the data base
 * @return void
 */
void Database::init() {
    // Iterate over member file list
    std::istringstream sstream(fileContent);
    char del = '\n';
    string line;
    // Read one line at a time
    while (std::getline(sstream, line, del)) {
        Vector v;
        // Init vector from the line, then push it into member Vector list
        try {
            v.initFromString(line);
        }
        catch (std::ios_base::failure const &ex) {
            throw;
        }
        this->vectors.push_back(v);
    }
    if (this->vectors.empty()) { // Exit if database contains no vectors
        throw std::ios_base::failure("File contains no valid vectors. Exiting program");
    } else if (this->vectors.size() > 1) { // Exit if database contains vectors of different sizes
        for (Vector vec: this->vectors) {
            if (vec.size() != this->vectors[0].size()) {
                throw std::ios_base::failure(
                        "File contains vectors of differing sizes. Exiting program");
            }
        }
    }
}

/**
 * Print the database.
 */
void Database::print() {
    if (!this->vectors.empty()) {
        for (Vector v: this->vectors) {
            v.print();
        }
    } else {
        std::cout << "Database is empty" << std::endl;
    }
}

/**
 * @brief init the vectors distances by the correct function.
 * @param funcIdent - function name
 * @param v - arg vector.
 */
void Database::initVectors(Vector v) {
    for (Vector &vec: this->vectors) {
        (*distance)(vec, v);
    }
}

/**
 * @brief find the k nearest neighbors
 * @param v - argument vector
 * @param code - function name
 * @return string - classification
 */
string Database::knn(Vector &v, const string &distanceFunction, int k) {
    std::map<string, Distances *> map;
    Comparator comparator;
    // Create a vector of pairs, where the first element is the distance,
    // and the second is the index of the vector
    vector<std::pair<double, string>> classifyKnearest;
    initDistances(distanceFunction, map);
    Database::initVectors(v);
    // Sort the vector by distance function
    std::sort(this->vectors.begin(), this->vectors.end(), comparator);
    for (int i = 0; i < k; i++) {
        classifyKnearest.emplace_back(this->vectors[i].getDistFromArg(),
                                      this->vectors[i].getClassification());
    }

    std::map<string, int> classificationCount;
    for (int i = 0; i < k; i++) {
        classificationCount[classifyKnearest[i].second]++;
    }
    // Find the classification with the most votes
    int max = 0;
    string classification;
    for (auto &i: classificationCount) {
        if (i.second > max) {
            max = i.second;
            classification = i.first;
        }
    }
    // Delete the distances map
    for (auto &i: map) {
        delete i.second;
    }
    this -> distance = nullptr;
    return classification;
}

/**
 * @brief get the size of a vector in the database
 * @return size of vector
 */
unsigned long Database::getVectorSize() {
    return this->vectors[0].size();
}

/**
 * Get the size of the database
 * @return size of database
 */
int Database::size() {
    return this->vectors.size();
}

/**
 * Create corresponding distance functor from string input and initialize the map of distances.
 * @param s - distance function name
 */
void Database::initDistances(const string &s,std::map<string, Distances*> &map) {
    map["AUC"] = new AUC();
    map["CHB"] = new CHB();
    map["CAN"] = new CAN();
    map["MIN"] = new MIN();
    map["MAN"] = new MAN();
    // Check if the distance function is valid
    if (map.find(s) != map.end()) {
        this->distance = map[s];
    }
//    else {
//        throw std::ios_base::failure("Invalid distance function. Exiting program");
//    }
}









