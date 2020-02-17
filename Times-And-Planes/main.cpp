#include <iostream>
#include <vector>
#include "Read_CheckPoints.h"
#include "Read_Scheme.h"
#include "CheckPoint.h"
#include "Scheme.h"

using namespace std;


int main() {

    vector<CheckPoint> checkPoints;
    vector<Scheme> schemes;

    map<string,size_t> pointNameToID;

    string nameOfPointsFile = "CheckPointTest1.txt";
    Read_CheckPoints(nameOfPointsFile, checkPoints, pointNameToID);

    string nameOfSchemeFile = "SchemeTest.txt";
    Read_Scheme(nameOfSchemeFile, checkPoints, pointNameToID, schemes);


    return 0;
}
