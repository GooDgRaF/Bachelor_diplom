//
// Created by Антон on 07.05.2020.
//

#include "Calculate standard scheme.h"

#define _USE_MATH_DEFINES

#include <cmath>

void calcStScheme(vector<CheckPoint> &checkPoints, StandardScheme &stScheme)
	{
		Time tmin = Time::createTsec(0);
		Time tmax = Time::createTsec(0);
		
		Coordinate R = Coordinate::createMs(0); //Радиус поворота
		
		Coordinate S = Coordinate::createMs(0); //Длина плеча
		
		Coordinate x0 = checkPoints[stScheme.start].x;
		Coordinate y0 = checkPoints[stScheme.start].y;
		Coordinate z0 = checkPoints[stScheme.start].z;
		Velocity vmin = checkPoints[stScheme.start].Vmin;
		Velocity vmax = checkPoints[stScheme.start].Vmax;
		
		
		Coordinate x1 = checkPoints[stScheme.second].x;
		Coordinate y1 = checkPoints[stScheme.second].y;
		Coordinate z1 = checkPoints[stScheme.second].z;
		
		
		Coordinate x2 = checkPoints[stScheme.third].x;
		Coordinate y2 = checkPoints[stScheme.third].y;
		Coordinate z2 = checkPoints[stScheme.third].z;
		
		R = 0.5 * (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2)));  //sqt((x1-x0)^2+...)
		
		S = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
		
		tmin = 2 * M_PI * R / vmax;
		tmax = 2 *(S + M_PI * R) /  vmin;
		
		stScheme.Tmin = tmin;
		stScheme.Tmax = tmax;
		
	}
