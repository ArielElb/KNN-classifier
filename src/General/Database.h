#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Comparator.h"
#include "Distances/AUC.h"
#include "Distances/CAN.h"
#include "Distances/CHB.h"
#include "Distances/MAN.h"
#include "Distances/MIN.h"
#include "Vector.h"

using std::vector;
using std::istream;

class Database {

private:
    std::map<string, Distances *> map;
    vector<Vector> trainVectors;
    vector<Vector> testVectors;
    Distances *distance;
    string distanceName;
    std::string classifications;


    int k;

public:
    explicit Database();
    ~Database();
    void initVectors(Vector v);
    void initDistances();
    unsigned long getVectorSize();
    bool isKValid(int k);
    void setK(int k);
    void setDistanceFunction(string s);
    std::string getK();
    std::string getDistanceFunction();
    int size();
    void print();
    void initTrainVectors(string fileTrainVectors);
    void initTestVectors(string fileTestVectors);
    string knn();
    bool isFilesUnloaded();
    std::string getClassfications();
    void setClassfications(const char *string);
    void resetFiles();
};

#endif
