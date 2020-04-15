//
// Created by Антон on 14.04.2020.
//

#include "Function_MergeTimes.h"
#include <map>
#include <iostream>

void mergeTimes(vector<pair<int, int>> &times)
	{
		map<int, int> valueAction; //Значение - действие
		for (auto pair : times)
		{
			if (pair.first > pair.second)
			{
				throw runtime_error("Warning first element of pair is bigger than second");
			}
			
			valueAction[pair.first]++;
			valueAction[pair.second]--;
		}
		
		times.clear();
		
		int sum = 0;
		auto itMap = valueAction.begin();
		int start = itMap->first;
		for (itMap = valueAction.begin(); itMap != valueAction.end(); itMap++)
		{
			sum = sum + itMap->second;
			if (sum == 0)
			{
				times.push_back({start, itMap->first});
				itMap++;
				start = itMap->first;
				itMap--;
			}
		}
		
		
	}
