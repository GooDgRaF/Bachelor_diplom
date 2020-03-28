//
// Created by Антон on 09.03.2020.
//
#include <map>
#include "Maps.h"
#include "Function_Find-InMap.h"

int findValueINpointNameToID(const string &Key)
	{
		map<string, int>::iterator res = pointNameToID.find(Key);
		if (res == pointNameToID.end()) //Неудачный поиск, сообщить об ошибке
		{
			throw runtime_error(Key);
		}
		return res->second;
	}
