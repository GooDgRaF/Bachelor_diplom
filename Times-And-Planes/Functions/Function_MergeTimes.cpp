//
// Created by Антон on 14.04.2020.
//

#include "Function_MergeTimes.h"

#include <map>
#include <iostream>

double epsilon = 0.0001;

/*
struct doubleCompLess
{
	bool operator()(const double a, const double b)
		{
			return (abs(a - b) >= epsilon) && (a < b);
		}
};

struct doubleCompGreater
{
	bool operator()(const double a, const double b)
		{
			return (abs(a - b) >= epsilon) && (a > b);
		}
};
*/

void mergeTimes(vector<pair<Time, Time>> &times)
	{
		compGreater compGr;
		map<Time, int, compLess> valueAction; //Значение - действие
		for (auto pair : times)
		{
			if (compGr(pair.first, pair.second))
			{
				throw runtime_error("Warning: first element of pair is bigger than second");
			}
			
			valueAction[pair.first]++;
			valueAction[pair.second]--;
		}
		
		times.clear();
		
		int sum = 0;
		auto itMap = valueAction.begin();
		Time start = itMap->first;
		for (itMap = valueAction.begin(); itMap != valueAction.end(); itMap++)
		{
			sum = sum + itMap->second;
			if (sum == 0)
			{
				times.push_back({start, itMap->first});
				if (itMap != valueAction.end())
				{
					itMap++;
					start = itMap->first;
					itMap--;
				}
			}
		}
		
		
	}
