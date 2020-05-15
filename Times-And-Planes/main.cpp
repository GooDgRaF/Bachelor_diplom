#include <iostream>
#include "Read/Read_SchemeRegExp.h"
#include "Zone.h"
#include "Stage -1.h"
#include "Calculating times.h"

using namespace std;

int main()
	{
		Zone zone;
		
		string nameOfPointsFile = "D:/Work/Bachelor_diplom/Times-And-Planes/Source information/Points/Koltsovo.txt";//TestFastStrReg CheckPointEzTimeTest.txt CheckPointTestTwoFlowsTopSort
		string nameOfSchemeFile = "D:/Work/Bachelor_diplom/Times-And-Planes/Source information/Schemes/Koltsovo.txt";//SchemeEzTimeTest.txt SchemeTestTwoFlows
		string nameOfFlowsFile = "D:/Work/Bachelor_diplom/Times-And-Planes/Source information/Flows/Koltsovo.txt"; //EzFlowTimeTest.txt TwoFlowsTest
		
		stage_minus_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		for (auto &flow : zone.flows)
		{
			calculateTimes(zone, flow);
		}
		
		zone.print_times();
		
		
		return 0;
	}
