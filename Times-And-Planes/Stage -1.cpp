//
// Created by Антон on 14.04.2020.
//
#include <Build/Build_Zone.h>
#include <Build/Build_Flow.h>
#include <Read/Read_CheckPointsRegExp.h>
#include "Stage -1.h"
#include "Read/Read_CheckPoints.h"
#include "Read/Read_Scheme.h"
#include "Read/Read_Flow.h"
#include "Functions/Topologic_Sort.h"

void stage_minus_one(string &path_checkPointsFile, string &path_SchemesFile, string &path_FlowsFile, Zone &zone)
	{
		Read_CheckPointsRegExp(path_checkPointsFile, zone.checkPoints);
		zone.graph_of_descendants.resize(zone.checkPoints.size());
		
		Read_Scheme(path_SchemesFile, zone.checkPoints, zone.schemes);
		
		Read_Flow(path_FlowsFile, zone.flows);
		
		Build_Zone(zone.schemes, zone.graph_of_descendants);
		
		for (auto &flow : zone.flows)
		{
			Build_Flow(zone, flow);
		}
		
		for (auto &flow : zone.flows)
		{
			topologicalSort_of_flow(flow);
		}
	}


