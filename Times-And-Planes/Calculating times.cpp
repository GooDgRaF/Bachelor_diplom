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
			
			
			double x0 = zone.checkPoints[flow.keys[i]].x;
			double y0 = zone.checkPoints[flow.keys[i]].y;
			double z0 = zone.checkPoints[flow.keys[i]].z / 1000;//Метры в км
			double vmin0 = zone.checkPoints[flow.keys[i]].Vmin;
			double vmax0 = zone.checkPoints[flow.keys[i]].Vmax;
			
			
			for (auto son : flow.graph_of_descendants[flow.keys[i]])
			{
				
				double x1 = zone.checkPoints[son].x;
				double y1 = zone.checkPoints[son].y;
				double z1 = zone.checkPoints[son].z / 1000;//Метры в км
				double vmin1 = zone.checkPoints[son].Vmin;
				double vmax1 = zone.checkPoints[son].Vmax;
				
				
				double S = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2));  //sqt((x1-x0)^2+...)
				double tmin, tmax;
				
				tmin = 2 * S / (vmax0 + vmax1);
				tmax = 2 * S / (vmin0 + vmin1);
				
				for (auto pair : zone.checkPoints[flow.keys[i]].times)
				{
					zone.checkPoints[son].times.push_back({pair.first + tmin,
														   pair.second + tmax});
				}
			}
		}
	}
