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
		
		string nameOfPointsFile = R"(E:\Works\Diplom\Bachelor_diplom\Points\CheckPointTestTwoFlowsTopSort.txt)";//TwoFlowsTopSort
		Read_CheckPoints(nameOfPointsFile, zone.checkPoints);
		zone.graph_of_descendants.resize(zone.checkPoints.size());
		
		
		string nameOfSchemeFile = R"(E:\Works\Diplom\Bachelor_diplom\Schemes\SchemeTestTwoFlows.txt)";//TwoFlows
		Read_Scheme(nameOfSchemeFile, zone.checkPoints, zone.schemes);
		
		
		string nameOfFlowsFile = R"(E:\Works\Diplom\Bachelor_diplom\Flows\TwoFlowsTest.txt)";
		Read_Flow(nameOfFlowsFile, zone.flows);
		
		
		Build_Zone(zone.schemes, zone.graph_of_descendants);
		
		for (auto &flow : zone.flows)
		{
			Build_Flow(zone, flow);
		}
		
		for (auto &flow : zone.flows)
		{
			topologicalSort_of_flow(flow);
		}
	

	zone.print_flows_keys();
		zone.print_flows_as_string_des();
		zone.print_flows_as_string_anc();
		zone.print_flows_as_string_des(true);
		

		
		return 0;
	}
