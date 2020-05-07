//
// Created by Антон on 09.03.2020.
//

#include <sstream>
#include "Function_Fill-scheme.h"
#include "Fields of Zone/Maps.h"

void fillScheme(const string &str, vector<int> &field)
	{
		stringstream ss(str);
		string token;
		while (ss >> token)
		{
			try
			{
				field.push_back(pointNameToID.at(token));
			}
			catch (const out_of_range &ex)
			{
				throw runtime_error(token);
			}
		}
	}