//
// Created by Антон on 28.03.2020.
//

#include <fstream>
#include <iostream>
#include "Read_Flow.h"
#include "Fields of Zone/Flow.h"
#include "Functions/OpenFile.h"
#include "Fields of Zone/Maps.h"

void Read_Flow(const string &name_of_file, vector<Flow> &flows)
	{
		int k;
		
		ifstream FlowsFile;
		
		openFile(name_of_file, FlowsFile);
		
		FlowsFile >> k; //Первым лежит количество потоков
		
		flows.resize(k);
		
		for (auto &flow : flows)
		{
			string token;
			FlowsFile >> flow.name >> token;
			try
			{
				flow.start_point = pointNameToID.at(token);
			}
			catch (const out_of_range &ex) //Ловим ошибку о не обнаружении точки из потока среди точек из checkPoints
			{
				cerr << "Can't find '" << token << "' among points from Points file" << endl;
				exit(-2);
			}
		}
	}
