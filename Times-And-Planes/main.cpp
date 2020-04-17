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
		
		string nameOfPointsFile = "D:/Work/Bachelor_diplom/Points/CheckPointEzTimeTest.txt";//CheckPointEzTimeTest.txt CheckPointTestTwoFlowsTopSort
		string nameOfSchemeFile = "D:/Work/Bachelor_diplom/Schemes/SchemeEzTimeTest.txt";//SchemeEzTimeTest.txt SchemeTestTwoFlows
		string nameOfFlowsFile = "D:/Work/Bachelor_diplom/Flows/EzFlowTimeTest.txt"; //EzFlowTimeTest.txt TwoFlowsTest
		
		stage_negative_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		for (auto &flow : zone.flows)
		{
			calculateTimes(zone, flow);
		}
		
		zone.print_times();
		
		
		return 0;
	}
