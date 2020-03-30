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


using namespace std;

struct Zone
{
	vector<vector<int>> graph_of_descendants; //Граф зоны задан списками Следующий
	vector<CheckPoint> checkPoints;
	vector<Scheme> schemes;
	vector<Flow> flows;
	
	int Index_of(vector<int> &v, int a);
	
	void print_flows_keys();
	
	void print_key_of_flow(int number_of_flow);
	
	void print_as_string();
	
	void print_as_int();
	
	void print_flows_as_string();
	
	void print_flows_as_string(bool sort);
};


#endif //TIMES_AND_PLANES_ZONE_H
