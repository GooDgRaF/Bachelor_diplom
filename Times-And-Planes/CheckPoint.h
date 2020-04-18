//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_CHECKPOINT_H
#define TIMES_AND_PLANES_CHECKPOINT_H

#include <string>
#include <Measure units/Coordinate.h>

using namespace std;

struct CheckPoint
{
	string name;
	Coordinate x = Coordinate::createMs(0); //В километрах
	Coordinate y = Coordinate::createMs(0); //В километрах
	Coordinate z = Coordinate::createMs(0); //В метрах
	double Vmin;
	double Vmax; //В км/ч
	bool Landing_flag;
	vector<pair<double, double>> times; //Набор временных интервалов (Tmin, Tmax) в минутах
};

#endif //TIMES_AND_PLANES_CHECKPOINT_H
