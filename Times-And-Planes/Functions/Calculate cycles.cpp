//
// Created by Антон on 07.05.2020.
//

#include "Calculate cycles.h"

void calcCycle(vector<CheckPoint> &checkPoints, Cycle &cycle)
	{
		Time tmin = Time::createTsec(0);
		Time tmax = Time::createTsec(0);
		
		for (int i = 0; i < cycle.path.size() - 1; i++)
		{
			Coordinate x0 = checkPoints[cycle.path[i]].x;
			Coordinate y0 = checkPoints[cycle.path[i]].y;
			Coordinate z0 = checkPoints[cycle.path[i]].z;
			Velocity vmin0 = checkPoints[cycle.path[i]].Vmin;
			Velocity vmax0 = checkPoints[cycle.path[i]].Vmax;
			
			Coordinate x1 = checkPoints[cycle.path[i + 1]].x;
			Coordinate y1 = checkPoints[cycle.path[i + 1]].y;
			Coordinate z1 = checkPoints[cycle.path[i + 1]].z;
			Velocity vmin1 = checkPoints[cycle.path[i + 1]].Vmin;
			Velocity vmax1 = checkPoints[cycle.path[i + 1]].Vmax;
			
			Coordinate S = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2));  //sqt((x1-x0)^2+...)
			
			tmin = 2 * S / (vmax0 + vmax1);
			tmax = 2 * S / (vmin0 + vmin1);
			
			cycle.Tmin = tmin;
			cycle.Tmax = tmax;
		}
	}
