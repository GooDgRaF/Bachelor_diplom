#include <iostream>
#include "Read/Read_SchemeRegExp.h"
#include "Zone.h"
#include "Stage -1.h"
#include "Functions/Calculate times.h"

using namespace std;

int main()
	{
		Zone zone;
		
		string nameOfPointsFile = "../Source information/Points/KoltsovoStScheme.txt";//Test.txt
		string nameOfSchemeFile = "../Source information/Schemes/KoltsovoStScheme.txt";//Test.txt
		string nameOfFlowsFile = "../Source information/Flows/Koltsovo.txt";
		
		stage_minus_one(nameOfPointsFile, nameOfSchemeFile, nameOfFlowsFile, zone);
		
		for (auto &flow : zone.flows)
		{
			calculateTimes(zone, flow);
		}
		
		zone.print_times();
		
		
		return 0;
	}
