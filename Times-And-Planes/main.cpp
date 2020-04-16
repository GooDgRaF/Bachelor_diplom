#include <iostream>
#include "Read/Read_Scheme.h"
#include "Zone.h"
#include "Stage -1.h"
#include "Functions/Function_MergeTimes.h"
#include "Calculating times.h"

using namespace std;

int main()
	{
		Zone zone;
		
		string nameOfPointsFile = R"(E:\Works\Diplom\Bachelor_diplom\Points\CheckPointTestTwoFlowsTopSort.txt)";//CheckPointEzTimeTest.txt TwoFlowsTopSort
		string nameOfSchemeFile = R"(E:\Works\Diplom\Bachelor_diplom\Schemes\SchemeTestTwoFlows.txt)";//SchemeEzTimeTest.txt TwoFlows
		string nameOfFlowsFile = R"(E:\Works\Diplom\Bachelor_diplom\Flows\TwoFlowsTest.txt)"; //EzFlowTimeTest.txt
		
		stage_negative_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		for (auto &flow : zone.flows)
		{
			calculateTimes(zone, flow);
		}
		
		zone.print_times();
		
		
		return 0;
	}
