//
// Created by Антон on 14.04.2020.
//

#include "Calculating times.h"
#include "Functions/MergeTimes.h"
#include "Fields of Zone/Maps.h"
#include <cmath>
#include <iostream>

void calculateTimes(Zone &zone, Flow &flow)
	{
		for (int i = 0; i < flow.graph_of_descendants.size();)
		{
			int j = flow.keys[i]; //Изначальый ID точки
			try
			{
				if (zone.checkPoints[j].landing_flag == true)
				{
					mergeTimes(flow.land_points_times[j]);
				}
				mergeTimes(zone.checkPoints[j].times);
			}
			catch (runtime_error &er)
			{
				cerr << er.what() << " on " << zone.checkPoints[j].name << endl;
				exit(-5);
			}
			
			if ((pointIDtoStartCycleID.count(j)) //Если точка является началом цикла и остались повторения цикла
				&& (zone.cycles[pointIDtoStartCycleID[j]].repeat > 0))
			{
				for (auto &pair : zone.checkPoints[j].times)
				{
					zone.checkPoints[j].times.push_back({pair.first + zone.cycles[pointIDtoStartCycleID[j]].Tmin,
														 pair.second + zone.cycles[pointIDtoStartCycleID[j]].Tmax});
				}
				zone.cycles[pointIDtoStartCycleID[j]].repeat--;
				i = distance(flow.keys.begin(), find(flow.keys.begin(), flow.keys.end(), zone.cycles[pointIDtoStartCycleID[j]].finish));
			}
			else
			{
				Coordinate x0 = zone.checkPoints[j].x;
				Coordinate y0 = zone.checkPoints[j].y;
				Coordinate z0 = zone.checkPoints[j].z;
				Velocity vmin0 = zone.checkPoints[j].Vmin;
				Velocity vmax0 = zone.checkPoints[j].Vmax;
				
				
				for (auto son : flow.graph_of_descendants[j])
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
					
					if (zone.checkPoints[son].landing_flag == true) //Если следующая точка посадочная
					{
						if (zone.checkPoints[j].landing_flag == true) //Если текущая точка посадочная
						{
							for (auto &pair : flow.land_points_times[j]) //Если следующая посадочная и текущая посадочная
							{
								flow.land_points_times[son].push_back({pair.first + tmin, pair.second + tmax});
							}
						}
						else //Если следующая посадочная, а текущая обычная
						{
							for (auto &pair : zone.checkPoints[j].times)
							{
								flow.land_points_times[son].push_back({pair.first + tmin, pair.second + tmax});
							}
						}
					}
					
					for (auto &pair : zone.checkPoints[j].times) //Если следующая и текущая точки обычные
					{
						zone.checkPoints[son].times.push_back({pair.first + tmin, pair.second + tmax});
					}
				}
				i++;
			}
			
		}
	}
