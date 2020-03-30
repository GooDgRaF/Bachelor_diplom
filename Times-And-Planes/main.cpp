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
#include "Build/Build_Flow.h"

using namespace std;

int main()
	{
		Zone zone;
		
		string nameOfPointsFile = R"(E:\Works\Diplom\Bachelor_diplom\Points\CheckPointTestTwoFlowsTopSort.txt)";
		Read_CheckPoints(nameOfPointsFile, zone.checkPoints);
		zone.graph_of_descendants.resize(zone.checkPoints.size());
		
		
		string nameOfSchemeFile = R"(E:\Works\Diplom\Bachelor_diplom\Schemes\SchemeTestTwoFlows.txt)";
		Read_Scheme(nameOfSchemeFile, zone.checkPoints, zone.schemes);
		
		
		string nameOfFlowsFile = R"(E:\Works\Diplom\Bachelor_diplom\Flows\TwoFlowsTest.txt)";
		Read_Flow(nameOfFlowsFile, zone.flows);
		
		
		Build_Zone(zone.schemes, zone.graph_of_descendants);
		
		Build_Flow(zone,zone.flows[0],zone.flows[0].start_point);
		Build_Flow(zone,zone.flows[1],zone.flows[1].start_point);
		
		
		topologicalSort(zone.flows[0].graph_of_descendants,zone.flows[0].keys);
		topologicalSort(zone.flows[1].graph_of_descendants,zone.flows[1].keys);

		zone.print_flows_keys();
		zone.print_flows_as_string();
		zone.print_flows_as_string(true);
		

		
		return 0;
	}
