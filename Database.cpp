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
Database::Database() {
    initDistances();
    // Create string vector for class parameter
    this->distance = this->map["EUC"];
    this->distanceName = "EUC";
    this-> k = 5;
    this->trainVectors = vector<Vector>();
    this->testVectors = vector<Vector>();
}



void Database::print() {
    if (!this->trainVectors.empty()) {
        for (Vector v: this->trainVectors) {
            v.print();
        }
    } else {
        std::cout << "Database is empty" << std::endl;
    }
}

/**
 * @brief initVectors the trainVectors distances by the correct function.
 * @param funcIdent - function name
 * @param v - arg vector.
 */
void Database::initVectors(Vector v) {
    for (Vector &vec: this->trainVectors) {
        (*distance)(vec, v);
    }
}
/**
 * @brief find the k nearest neighbors
 * @param v - argument vector
 * @param code - function name
 * @return string - classification
 */
string Database::knn(Vector &v,int k) {

    Comparator comparator;
    // Create a vector of pairs, where the first element is the distance,
    // and the second is the index of the vector
    vector<std::pair<double, string>> classifyKnearest;
    Database::initVectors(v);
    // Sort the vector by distance function
    std::sort(this->trainVectors.begin(), this->trainVectors.end(), comparator);
    for (int i = 0; i < k; i++) {
        classifyKnearest.emplace_back(this->trainVectors[i].getDistFromArg(),
                                      this->trainVectors[i].getClassification());
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

    return classification;
}

/**
 * @brief get the size of a vector in the database
 * @return size of vector
 */
unsigned long Database::getVectorSize() {
    return this->trainVectors[0].size();
}

/**
 * Get the size of the database
 * @return size of database
 */
int Database::size() {
    return this->trainVectors.size();
}

/**
 * Create corresponding distance functor from string input and initialize the map of distances.
 * @param s - distance function name
 */
void Database::initDistances() {
    this->map["AUC"] = new AUC();
    this->map["CHB"] = new CHB();
    this->map["CAN"] = new CAN();
    this->map["MIN"] = new MIN();
    this->map["MAN"] = new MAN();
}

void Database::setK(int k) {
    this->k = k;
}
void Database::setDistanceFunction(string s) {
    this->distanceName = s;
    this->distance = this->map[s];
}

Database::~Database() {
    // Delete the distances map
    for (auto &i: this->map) {
        delete i.second;
    }
    this -> distance = nullptr;
}

void Database::initTestVectors(string fileTestVectors) {
    std::istringstream stream(fileTestVectors);
    char del = '\n';
    string line;
    // Read one line at a time
    while (std::getline(stream, line, del)) {
        Vector v;
        // Init vector from the line, then push it into member Vector list
        try {
            v.initFromString(line);
        }
        catch (std::ios_base::failure const &ex) {
            throw;
        }
        this->testVectors.push_back(v);
    }
    if (this->testVectors.empty()) { // Exit if database contains no trainVectors
        throw std::ios_base::failure("File contains no valid trainVectors. Exiting program");
    } else if (this->testVectors.size() > 1) { // Exit if database contains
        for (Vector vec: this->testVectors) {
            if (vec.size() != this->testVectors[0].size()) {
                throw std::ios_base::failure(
                        "File contains trainVectors of differing sizes. Exiting program");
            }
        }
    }

}

void Database::initTrainVectors(string fileTrainVectors) {
    // Read the file
    // Iterate over member file list
    std::istringstream sstream(fileTrainVectors);
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
        this->trainVectors.push_back(v);
    }
    if (this->trainVectors.empty() ) { // Exit if database contains no trainVectors
        throw std::ios_base::failure("File contains no valid trainVectors. Exiting program");
    } else if (this->trainVectors.size() > 1) { // Exit if database contains
        for (Vector vec: this->trainVectors) {
            if (vec.size() != this->trainVectors[0].size()) {
                throw std::ios_base::failure(
                        "File contains trainVectors of differing sizes. Exiting program");
            }
        }
    }

}

std::string Database::getK() {
    return std::to_string(this->k);
}

std::string Database::getDistanceFunction() {
    return this -> distanceName;
}











