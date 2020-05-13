//
// Created by Антон on 14.04.2020.
//
#include <Build/Build_Zone.h>
#include <Build/Build_Flow.h>
#include <Read/Read_CheckPointsRegExp.h>
#include "Stage -1.h"
#include "Read/Read_SchemeRegExp.h"
#include "Read/Read_FlowRegExp.h"
#include "Functions/Topologic_Sort.h"

void stage_minus_one(string &path_checkPointsFile, string &path_SchemesFile, string &path_FlowsFile, Zone &zone)
	{
		Read_CheckPointsRegExp(path_checkPointsFile, zone.checkPoints);
		zone.graph_of_descendants.resize(zone.checkPoints.size());
		
		Read_SchemeRegExp(path_SchemesFile, zone.checkPoints, zone.schemes, zone.cycles);
		
		Read_FlowRegExp(path_FlowsFile, zone.flows);
		
		Build_Zone(zone);
		
		for (auto &flow : zone.flows)
		{
			Build_Flow(zone, flow);
		}
		
		for (auto &flow : zone.flows)
		{
			topologicalSort_of_flow(flow);
		}
	}


