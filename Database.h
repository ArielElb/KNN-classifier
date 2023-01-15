#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"
#include "Distances.h"
#include "CHB.h"
#include "AUC.h"
#include "MIN.h"
#include "MAN.h"
#include "CAN.h"
#include "Comparator.h"
#include "map"

using std::vector;
using std::istream;

class Database {

private:
    string fileContent;
    vector<Vector> vectors;
    Distances *distance;

public:
    Database(const string &s);

    void init();

    void initVectors(Vector v);

    void initDistances(const string &s, std::map<string, Distances *> &map);

    unsigned long getVectorSize();

    int size();

    string knn(Vector &v, const string &distanceFunction, int k);

    void print();
};

#endif
