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
		
		string nameOfPointsFile = R"(E:\Works\Diplom\Bachelor_diplom\Points\CheckPointEzTimeTest.txt)";//TwoFlowsTopSort
		string nameOfSchemeFile = R"(E:\Works\Diplom\Bachelor_diplom\Schemes\SchemeEzTimeTest.txt)";//TwoFlows
		string nameOfFlowsFile = R"(E:\Works\Diplom\Bachelor_diplom\Flows\EzFlowTimeTest.txt)";
		
		stage_negative_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		calculateTimes(zone,zone.flows[0]);
		zone.print_times();

		
		return 0;
	}
