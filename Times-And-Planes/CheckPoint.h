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
	double x; //В кимлометрах
	double y;
	double z;
	double Vmin;
	double Vmax; //В км/ч
	bool Landing_flag;
	vector<pair<double, double>> times; //Набор временных интервалов (Tmin, Tmax) в секундах
};

#endif //TIMES_AND_PLANES_CHECKPOINT_H
