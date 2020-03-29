//
// Created by Антон on 10.02.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Maps.h"
#include "CheckPoint.h"
#include "Functions/Function_OpenFile.h"

using namespace std;


void Read_CheckPoints(const string &name_of_file, vector<CheckPoint> &checkPoints)
	{
		size_t k = 0;
		
		ifstream CheckPointFile;
		
		openFile(name_of_file, CheckPointFile);
		
		CheckPointFile >> k; //Первым лежит значение сколько точек всего
		
		checkPoints.resize(k);
		
		for (size_t i = 0; i < k; i++)
		{
			string tmp;
			CheckPointFile >> tmp;
			for (const auto &el : checkPoints) //Проверка, чтобы две точки с одинаковым названием не встречались
			{
				if (el.Name == tmp)
				{
					cerr << "Attention! " << tmp << " point occurs twice" << endl;
					exit(-3);
				}
			}
			checkPoints[i].Name = tmp;
			CheckPointFile >> checkPoints[i].x >> checkPoints[i].y >> checkPoints[i].z >>
						   checkPoints[i].Vmin >> checkPoints[i].Vmax;
			CheckPointFile >> tmp;
			checkPoints[i].Landing_flag = tmp == "LAND";
			pointNameToID[checkPoints[i].Name] = i;
		}
		
		k = 0;
		for (const auto &el : checkPoints) //Проверка, чтобы была точка с флагом посадки
		{
			if (el.Landing_flag == 0)
			{
				k++;
			}
		}
		
		if (k == checkPoints.size()) //Проверка, чтобы была точка с флагом посадки
		{
			cerr << "Attention! " << "The LAND flag is not found among points in " << name_of_file << endl;
			exit(-4);
		}
		if (k < checkPoints.size() - 1) //Проверка, чтобы не было более одной точки с флагом посадки
		{
			cerr << "Attention! " << "In " << name_of_file << " LAND flag occurs more than one time";
			exit(-5);
		}
		
		CheckPointFile.close();
		
	}

