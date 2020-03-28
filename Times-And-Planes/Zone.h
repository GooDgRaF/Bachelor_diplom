//
// Created by Антон on 27.03.2020.
//

#ifndef TIMES_AND_PLANES_ZONE_H
#define TIMES_AND_PLANES_ZONE_H

#include <vector>
#include <algorithm>
#include "CheckPoint.h"


using namespace std;

struct Zone
{
	vector<vector<int>> list_of_descendants; //Граф зоны задан списками Следующий
	vector<int> keys; //Массив для значений вершин после топологической сортировки
	vector<CheckPoint> checkPoints;
	vector<Scheme> schemes;
	vector<Flow> flows;
	
	int Index_of(vector<int> &v, int a)
		{
			return distance(v.begin(), find(v.begin(), v.end(), a));
		}
	
	void print_keys()
		{
			for (auto el : keys)
			{
				cout << el << " ";
			}
			cout << endl;
			
		}
	
	void print_as_string()
		{
			for (int i = 0; i < list_of_descendants.size(); ++i)
			{
				cout << checkPoints[i].Name << " --> ";
				for (auto el : list_of_descendants[i])
				{
					cout << checkPoints[el].Name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	
	void print_as_string(bool sort)
		{
			if (sort == true)
			{
				for (int i = 0; i < list_of_descendants.size(); ++i)
				{
					cout << checkPoints[keys[i]].Name << " --> ";
					for (auto el : list_of_descendants[keys[i]])
					{
						cout << checkPoints[el].Name << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				print_as_string();
			}
		}
	
	void print_as_int()
		{
			for (int i = 0; i < list_of_descendants.size(); ++i)
			{
				cout << pointNameToID[checkPoints[i].Name] << " --> ";
				for (auto el : list_of_descendants[i])
				{
					cout << pointNameToID[checkPoints[el].Name] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	
	void print_as_int(bool sort)
		{
			if (sort == true)
			{
				for (int i = 0; i < list_of_descendants.size(); ++i)
				{
					cout << i << " --> ";
					for (auto el : list_of_descendants[keys[i]])
					{
						cout << Index_of(keys, el) << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				print_as_int();
			}
		}
};


#endif //TIMES_AND_PLANES_ZONE_H
