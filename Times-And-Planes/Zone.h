//
// Created by Антон on 27.03.2020.
//

#ifndef TIMES_AND_PLANES_ZONE_H
#define TIMES_AND_PLANES_ZONE_H

#include <vector>
#include <algorithm>
#include "CheckPoint.h"
#include "Scheme.h"
#include "Flow.h"
#include "Measure units/MeasureUnits.h"


using namespace std;

struct Zone
{
	vector<vector<int>> graph_of_descendants; //Граф зоны задан списками Следующий
	vector<CheckPoint> checkPoints;
	vector<Scheme> schemes;
	vector<Flow> flows;
	
	void print_flows_keys();
	
	void print_key_of_flow(int number_of_flow);
	
	void print_as_string();
	
	void print_flows_as_string_des();
	
	void print_flows_as_string_anc();
	
	void print_flows_as_string_des(bool sort);
	
	void print_times();
};


#endif //TIMES_AND_PLANES_ZONE_H
