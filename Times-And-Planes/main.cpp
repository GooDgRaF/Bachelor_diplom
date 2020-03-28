#include <iostream>
#include <vector>
#include "Read/Read_CheckPoints.h"
#include "Read/Read_Scheme.h"
#include "CheckPoint.h"
#include "Scheme.h"
#include "Maps.h"
#include "Flow.h"
#include "Build/Build_Zone.h"
#include "Zone.h"
#include "Functions/Topologic_Sort.h"
#include "Read/Read_Flow.h"

using namespace std;

int main()
	{
		Zone zone;
		
		string nameOfPointsFile = "CheckPointTestTopSort.txt";
		Read_CheckPoints(nameOfPointsFile, zone.checkPoints);
		zone.list_of_descendants.resize(zone.checkPoints.size());
		
		
		string nameOfSchemeFile = "SchemeTest.txt";
		Read_Scheme(nameOfSchemeFile, zone.checkPoints, zone.schemes);
		
		
		string nameOfFlowsFile = "TwoFlowsTest.txt";
		//Read_Flow(nameOfFlowsFile, zone.flows);
		
		
		Build_Zone(zone.schemes, zone.list_of_descendants);
		
		
		
		zone.keys.resize(zone.list_of_descendants.size());
		topologicalSort(zone.list_of_descendants, zone.keys);
		
		zone.print_keys();
		zone.print_as_string();
		zone.print_as_string(true);
		zone.print_as_int();
		zone.print_as_int(true);
		
		return 0;
	}
