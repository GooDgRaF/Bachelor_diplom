#include <iostream>
#include <vector>
#include "Read_CheckPoints.h"
#include "Read_Scheme.h"
#include "CheckPoint.h"
#include "Scheme.h"
#include "Maps.h"

using namespace std;

int main() {

    vector<CheckPoint> checkPoints;
    vector<Scheme> schemes;


    string nameOfPointsFile = "CheckPointTest1.txt";
    Read_CheckPoints(nameOfPointsFile, checkPoints);

    string nameOfSchemeFile = "SchemeTest.txt";
    Read_Scheme(nameOfSchemeFile, checkPoints, schemes);


    return 0;
}
