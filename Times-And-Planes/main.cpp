#include <iostream>
#include "Read_CheckPoints.h"
#include "Read_Scheme.h"

using namespace std;

int main() {

    string nameOfPointsFile = "CheckPointTest.txt";
    Read_CheckPoints(nameOfPointsFile);

    string nameOfSchemeFile = "SchemeTest.txt";
    Read_CheckPoints(nameOfSchemeFile);


    return 0;
}
