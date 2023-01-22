#include <utility>
#include <valarray>

#include "Vector.h"

/**
 * Calculates the absolute value difference from another vector (useful for calculations)
 * @param other
 * @return
 */
vector<double> Vector::absValueDiff(Vector other) {
    // calculate the absolute value of the difference between each index
    // (p1, ... , pn) , (q1, ... , qn)
    // -> (|p1 - q1|, ... , |pn -qn|)
    if (v.size() != other.size()) {
        throw std::ios_base::failure("Vectors must be of the same size");
    }
    vector<double> result;
    for (int i = 0; i < v.size(); i++) {
        result.push_back(std::abs(this->get(i) - other.get(i)));
    }
    return result;
}

/**
 * Calculate the Euclidean distance
 * @param a - vector
 * @return euclidean distance
 */
double Vector::euclideanDistance(Vector &a) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a.get(i) * a.get(i);
    }
    return std::sqrt(sum);
}

/**
 * Calculate the manhattan distance
 * @param a - vector
 * @return manhattan distance
 */

double Vector::manhattanDistance(Vector &a) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a.get(i);
    }
    return sum;
}

/**
 * @brief calculate the maximum value in a vector
 * @param a -vector
 * @return chevyshev distance
 */
double Vector::chebyshevDistance(Vector &a) {
    double max = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.get(i) > max) {
            max = a.get(i);
        }
    }
    return max;
}

/**
 * @brief calculate the canberra distance
 * @param other - other vector
 * @param a - absDiff vector
 * @return - canberra distance
 */
double Vector::canberraDistance(Vector &other, Vector &a) {
    double sum = 0;
    for (int i = 0; i < this->size(); i++) {
        double numerator = a.get(i);
        double denominator = std::abs(this->get(i)) + std::abs(other.get(i));
        if (!denominator) {
            std::cout << "Error -- division by 0. Exiting program" << std::endl;
            std::exit(1);
        }
        sum += numerator / denominator;
    }
    return sum;
}

/**
 * @brief calculate the minkowski distance
 * @param a - vector
 * @return minkowski distance
 */
double Vector::minkowskiDistance(Vector &a) {
    return euclideanDistance(a);
}

/**
 * @brief default constructor
 */
Vector::Vector() = default;

/**
 * @brief constructor vector
 * @param vec
 */
Vector::Vector(vector<double> &vec) {
    this->v = vec;
}

/**
 * String constructor
 * @param s takes in string to initVectors vector
 */
Vector::Vector(std::string s) {
    initFromString(s);
}

/**
 * Extract double value from a string
 * @param b string to parse
 * @return double value of string
 */
double Vector::getNumber(string b) {
    double result = 0;
    // Number is negative, or regular (starts with a digit)
    if (isdigit(b[0]) || b[0] == '-') {
        bool dotCounter = false;
        bool minusCounter = false;
        for (int i = 0; i < b.length(); i++) {
            // Check if there are any invalid characters
            if (!isdigit(b[i]) && b[i] != '.' && b[i] != 'E' && b[i] != '-') {
                throw std::ios_base::failure("Invalid vector input. Exiting program");
            }
            // check if there is more than one dot
            if (b[i] == '.') {
                if (dotCounter) {
                    throw std::ios_base::failure("Invalid vector input. Exiting program");
                }
                // set dotCounter to true
                dotCounter = true;
                //check if the dot is the last character
                if (i == b.length() - 1) {
                    throw std::ios_base::failure("Invalid vector input. Exiting program");
                }
            }
            if (b[i] == '-') {
                if (minusCounter) {
                    throw std::ios_base::failure("Invalid vector input. Exiting program");
                }
                // set minusCounter to true
                minusCounter = true;
                // check if the minus is the last character
                if (i == b.length() - 1) {
                    throw std::ios_base::failure("Invalid vector input. Exiting program");
                }
            }
        }
        result = std::strtod(b.c_str(), nullptr);
    } else if (b[0] == '.') {
        for (int i = 1; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                throw std::ios_base::failure("Invalid vector input. Exiting program");
            }
        }
        result += (std::strtod(b.c_str(), nullptr));
    } else {
        throw std::ios_base::failure("Invalid vector input. Exiting program");
    }
    return result;
}

/**
 * @brief initialize vector from a string.
 * @param s - a string of vector values with/without classification suffix
 */
void Vector::initFromString(const string &s) {
    std::istringstream sstream(s);
    char del = ',';
    string b;
    vector<double> vec;
    while (std::getline(sstream, b, del)) {
        // Remove unnecessary whitespace from beginning of the string
        while (b[0] == ' ') {
            b = b.substr(1, b.length());
        }
        // Check for carry return character at end of string
        if (b[b.length() - 1] == 13) {
            b = b.substr(0, b.length() - 1);
        }
        // Try converting to double
        if (b[0] == '.' || isdigit(b[0]) || b[0] == '-') {
            try {
                double d = getNumber(b);
                vec.push_back(d);
            } catch (std::ios_base::failure const &ex) {
                throw;
            }
        } else {
            break;
        }
    }
    // Set classification if applicable
        if (!(b[0] == '.' || isdigit(b[0]) || b[0] == '-')) {
            this->classification = b;
            this->classified = true;
        }
    this->v = vec;
    this->distFromArg = 0;
}

/**
 * Print the vector.
 */
void Vector::print() {
    for (double d: this->v) {
        std::cout << d << " ";
    }
    if (this->classified) {
        std::cout << "Classified: " << this->classification << std::endl;
    } else {
        std::cout << "Not classified" << std::endl;
    }
}

/**
 * @brief initialize the vector
 * @param v - vector
 */
void Vector::init(vector<double> vec) {
    this->v = std::move(vec);
}

/**
 * @brief get the size of the vector
 * @return - size of the vector
 */
unsigned long Vector::size() {
    return v.size();
}

/**
 * @brief get the value at index i
 * @param i - index
 * @return - value at index i
 */
double Vector::get(int i) {
    return v[i];
}

/**
 * @brief calculate the distances between two trainVectors
 * @param other - vector
 * @return - vector of distances
 */
vector<double> Vector::getDistances(Vector &other) {
    // calculate abs value of difference
    Vector absDiff;
    try {
        absDiff.init(absValueDiff(other));
    } catch (...) {
        throw;
    }
    vector<double> distances;
    distances.push_back(euclideanDistance(absDiff));
    distances.push_back(manhattanDistance(absDiff));
    distances.push_back(chebyshevDistance(absDiff));
    distances.push_back(canberraDistance(other, absDiff));
    distances.push_back(minkowskiDistance(absDiff));
    return distances;
}

/**
 * @brief setter - set the dist from the arg
 * @param d - distFromArg
 */
void Vector::setDistFromArg(double d) {
    this->distFromArg = d;
}

/**
 * @brief getter - get the distance from the argument
 * @return distance
 */
double Vector::getDistFromArg() const {
    return this->distFromArg;
}

/**
 *
 * @brief getter - classify the vector
 * @return string - classification
 */
string Vector::getClassification() const {
    return this->classification;
}

/**
 * check if the trainVectors size are valid
 * @param size  - size of another vector
 */
void Vector::isInputValid(unsigned long size) {
    if (size != this->size()) {
        throw std::ios_base::failure("Invalid input");
    }
}
