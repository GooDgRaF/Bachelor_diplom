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
		
		string nameOfPointsFile = "E:/Works/Diplom/Bachelor_diplom/Times-And-Planes/Source information/Points/CheckPointEzTimeTest.txt";//CheckPointEzTimeTest.txt CheckPointTestTwoFlowsTopSort
		string nameOfSchemeFile = "E:/Works/Diplom/Bachelor_diplom/Times-And-Planes/Source information/Schemes/SchemeEzTimeTest.txt";//SchemeEzTimeTest.txt SchemeTestTwoFlows
		string nameOfFlowsFile = "E:/Works/Diplom/Bachelor_diplom/Times-And-Planes/Source information/Flows/EzFlowTimeTest.txt"; //EzFlowTimeTest.txt TwoFlowsTest
		
		stage_negative_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		for (auto &flow : zone.flows)
		{
			calculateTimes(zone, flow);
		}
		
		zone.print_times();
		
		
		return 0;
	}
