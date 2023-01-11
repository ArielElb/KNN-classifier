#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <sstream>
#include <vector>

using std::vector;
using std::string;

/**
 * @brief Vector class
 */
class Vector {
    
    bool classified = false;
    string classification;
    double distFromArg;
    vector<double> v;

    double getNumber(string s);

public:
    Vector();
    Vector(vector<double> &vec);
    Vector(string s);

    void initFromString(const string& s);
    void init(std::vector<double> v);

    unsigned long size();
    double get(int i);
    string getClassification() const;
    void isInputValid(unsigned long size);

    void setDistFromArg(double d);
    double getDistFromArg() const;

    vector<double> absValueDiff(Vector other);

    static double chebyshevDistance(Vector &a);
    static double euclideanDistance(Vector &a);
    double canberraDistance(Vector &other, Vector &a);
    static double manhattanDistance(Vector &a);
    static double minkowskiDistance(Vector &a);
    vector<double> getDistances(Vector &other);
    void print();
};

#endif //VECTOR_H
