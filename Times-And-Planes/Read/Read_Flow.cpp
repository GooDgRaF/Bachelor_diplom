//
// Created by Антон on 28.03.2020.
//

#include <fstream>
#include <iostream>
#include "Read_Flow.h"
#include "Flow.h"
#include "Functions/Function_OpenFile.h"
#include "Functions/Function_Find-InMap.h"
#include "Maps.h"

void Read_Flow(const string &name_of_file, vector<Flow> &flows)
	{
		int k;
		
		ifstream FlowsFile;
		
		openFile(name_of_file, FlowsFile);
		
		FlowsFile >> k; //Первым лежит количество потоков
		
		flows.resize(k);
		
		for (auto &flow : flows)
		{
			string tmp;
			FlowsFile >> flow.name >> tmp;
			try
			{
				flow.start_point = findValueINpointNameToID(tmp);
			}
			catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из потока среди точек из checkPoints
			{
				cerr << "Can't find " << ex.what() << " among points" << endl;
				exit(-2);
			}
		}
	}
