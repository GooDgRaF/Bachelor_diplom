#include <iostream>
#include <vector>
#include "Read_CheckPoints.h"
#include "Read_Scheme.h"
#include "CheckPoint.h"
#include "Scheme.h"
#include "Maps.h"
#include "Flow.h"
#include "Build_Flow.h"
#include "Functions/Topologic_Sort.h"

using namespace std;

int main() {

    vector<CheckPoint> checkPoints;
    vector<Scheme> schemes;
    vector<Flow> flows (7);


    string nameOfPointsFile = "CheckPointTestTopSort.txt";
    Read_CheckPoints(nameOfPointsFile, checkPoints);

    string nameOfSchemeFile = "SchemeTest.txt";
    Read_Scheme(nameOfSchemeFile, checkPoints, schemes);

    flows[0].graph_of_flow.resize(checkPoints.size());//????
    Build_Flow(schemes, flows[0].graph_of_flow);

    topologicalSort(flows[0].graph_of_flow, checkPoints.size());




    return 0;
}
