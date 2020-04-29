//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_CHECKPOINT_H
#define TIMES_AND_PLANES_CHECKPOINT_H

#include <string>
#include "Measure units/MeasureUnits.h"

using namespace std;

struct CheckPoint
{
	string name;
	Coordinate x = Coordinate::createMs(0);
	Coordinate y = Coordinate::createMs(0);
	Coordinate z = Coordinate::createMs(0);
	Velocity Vmin = Velocity::createVkm_h(0);
	Velocity Vmax = Velocity::createVkm_h(0);
	bool landing_flag;
	vector<pair<Time, Time >> times;//Набор временных интервалов (Tmin, Tmax)
};

#endif //TIMES_AND_PLANES_CHECKPOINT_H
