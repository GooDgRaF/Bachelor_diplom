//
// Created by Антон on 14.04.2020.
//

#include "Calculating times.h"
#include "Functions/Function_MergeTimes.h"
#include <cmath>
#include <iostream>

void calculateTimes(Zone &zone, Flow &flow)
	{
		for (int i = 0; i < flow.graph_of_descendants.size(); i++)
		{
			try
			{
				mergeTimes(zone.checkPoints[flow.keys[i]].times);
			}
			catch (runtime_error &er)
			{
				cerr << er.what() << " on " << zone.checkPoints[flow.keys[i]].name << endl;
				exit(-5);
			}
			
			
			Coordinate x0 = zone.checkPoints[flow.keys[i]].x;
			Coordinate y0 = zone.checkPoints[flow.keys[i]].y;
			Coordinate z0 = zone.checkPoints[flow.keys[i]].z;
			Velocity vmin0 = zone.checkPoints[flow.keys[i]].Vmin;
			Velocity vmax0 = zone.checkPoints[flow.keys[i]].Vmax;
			
			
			for (auto son : flow.graph_of_descendants[flow.keys[i]])
			{
				
				Coordinate x1 = zone.checkPoints[son].x;
				Coordinate y1 = zone.checkPoints[son].y;
				Coordinate z1 = zone.checkPoints[son].z;
				Velocity vmin1 = zone.checkPoints[son].Vmin;
				Velocity vmax1 = zone.checkPoints[son].Vmax;
				
				
				Coordinate S = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2));  //sqt((x1-x0)^2+...)
				Time tmin = Time::createTsec(0);
				Time tmax = Time::createTsec(0);
				
				
				tmin = 2 * S / (vmax0 + vmax1);
				tmax = 2 * S / (vmin0 + vmin1);
				
				for (auto pair : zone.checkPoints[flow.keys[i]].times)
				{
					zone.checkPoints[son].times.push_back({pair.first + tmin, pair.second + tmax});
				}
			}
		}
	}
