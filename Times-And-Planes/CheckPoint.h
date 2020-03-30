//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_CHECKPOINT_H
#define TIMES_AND_PLANES_CHECKPOINT_H

#include <string>

using namespace std;

struct CheckPoint
{
	string name;
	double x;
	double y;
	double z;
	double Vmin;
	double Vmax;
	bool Landing_flag;
};

#endif //TIMES_AND_PLANES_CHECKPOINT_H
