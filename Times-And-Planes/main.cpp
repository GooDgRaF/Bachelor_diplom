#include <iostream>
#include <vector>
#include "Read_/Read_CheckPoints.h"
#include "Read_/Read_Scheme.h"
#include "CheckPoint.h"
#include "Scheme.h"
#include "Maps.h"
#include "Flow.h"
#include "Build_/Build_Zone.h"
#include "Zone.h"
#include "Functions/Topologic_Sort.h"
#include "Read_/Read_Flow.h"

using namespace std;

int main()
	{
		
		vector<CheckPoint> checkPoints;
		vector<Scheme> schemes;
		vector<Flow> flows;
		Zone zone;
		
		
		string nameOfPointsFile = "CheckPointTestTwoFlows.txt";
		Read_CheckPoints(nameOfPointsFile, checkPoints);
		zone.graph.resize(checkPoints.size());
		
		
		string nameOfSchemeFile = "SchemeTestTwoFlows.txt";
		Read_Scheme(nameOfSchemeFile, checkPoints, schemes);
		
		
		string nameOfFlowsFile = "TwoFlowsTest.txt";
		Read_Flow(nameOfFlowsFile, flows);
		
		
		Build_Zone(schemes, zone.graph);
		
		
		//Методы для Zone: печать в разных вариантах
		
		zone.keys.resize(zone.graph.size());
		topologicalSort(zone.graph, zone.keys);
		
		
		return 0;
	}
