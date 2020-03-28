//
// Created by Антон on 27.03.2020.
//

#ifndef TIMES_AND_PLANES_ZONE_H
#define TIMES_AND_PLANES_ZONE_H

#include <vector>
#include "CheckPoint.h"

using namespace std;

struct Zone
{
	vector<vector<int>> graph; //Задан списками Следующий
	vector<int> keys; //Массив для значений вершин после топологической сортировки
	
	void print_keys()
		{
			for (auto el : keys)
			{
				cout << el << " ";
			}
			cout << endl;
			
		}
	
	void print_as_string(vector<CheckPoint> &checkPoints)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				cout << checkPoints[i].Name << " --> ";
				for (auto el : graph[i])
				{
					cout << checkPoints[el].Name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	
	/*void print_as_string(vector<CheckPoint> &checkPoints, bool sort)
		{
			if (sort == true)
			{
				for (int i = 0; i < graph.size(); ++i)
				{
					cout << checkPoints[keys[i]].Name << " --> ";
					for (auto el : graph[keys[i]])
					{
						cout << checkPoints[el].Name << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				print_as_string(checkPoints);
			}
		}*/ //Хелп
	
	void print_as_int(vector<CheckPoint> &checkPoints)
		{
			for (int i = 0; i < graph.size(); ++i)
			{
				cout << pointNameToID[checkPoints[i].Name] << " --> ";
				for (auto el : graph[i])
				{
					cout << pointNameToID[checkPoints[el].Name] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	
	/*void print_as_int(vector<CheckPoint> &checkPoints, bool sort)
		{
			if (sort == true)
			{
				for (int i = 0; i < graph.size(); ++i)
				{
					cout << keys[i] << " --> ";
					for (auto el : graph[keys[i]])
					{
						cout << keys[el] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				print_as_int(checkPoints);
			}
		}*/ //Хелп
};


#endif //TIMES_AND_PLANES_ZONE_H
