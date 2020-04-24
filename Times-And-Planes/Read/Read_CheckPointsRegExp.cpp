//
// Created by Антон on 22.04.2020.
//

#include "Read_CheckPointsRegExp.h"
#include <regex>
#include <fstream>
#include <Functions/Function_OpenFile.h>
#include <Maps.h>

using namespace std;

void Read_CheckPointsRegExp(const std::string &name_of_file, std::vector<CheckPoint> &checkPoints)
	{
		size_t k = 0;
		
		ifstream CheckPointFile;
		
		openFile(name_of_file, CheckPointFile);
		
		CheckPointFile >> k; //Первым лежит значение сколько точек всего
		
		checkPoints.resize(k);
		
		/*
		 * Пояснение к регулярному выражению:
		 * Всего 6 групп захвата, согласно формату:
		 * 1) - имя точки
		 * 2,3,4) - координаты x,y,z
		 * 5,6) - скорости vmin, vmax
		 * И ещё 7 группа захвата - поиск LAND
		 */
		
		string str;
		cmatch res;
		regex regular(R"((\w+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)(?:\s*)(\s*LAND)?)");
		
		int i = 0; // Счётчик, отвечающий за проход по chekpoints
		
		string tmp;
		getline(CheckPointFile, tmp); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(CheckPointFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + 2 << "' in " << name_of_file << " doesn't follow the input format" << endl;
				exit(-3);
			}
			
			for (const auto &el : checkPoints) //Проверка, чтобы две точки с одинаковым названием не встречались
			{
				if (el.name == res[1])
				{
					cerr << "Attention! '" << res[1] << "' point occurs twice" << endl;
					exit(-3);
				}
			}
			
			double x, y, z, vmin, vmax;
			
			x = atof(res[2].first);
			y = atof(res[3].first);
			z = atof(res[4].first);
			vmin = atof(res[5].first);
			vmax = atof(res[6].first);
			
			checkPoints[i].name = res[1];
			
			checkPoints[i].x = Coordinate::createKMs(x);
			checkPoints[i].y = Coordinate::createKMs(y); //В зависимости от исходных данных
			checkPoints[i].z = Coordinate::createMs(z);
			
			checkPoints[i].Vmin = Velocity::createVkm_h(vmin);
			checkPoints[i].Vmax = Velocity::createVkm_h(vmax);
			
			checkPoints[i].Landing_flag = res[7] == "LAND";
			
			pointNameToID[checkPoints[i].name] = i;
			
			
			if (vmin > vmax) //Проверка корректности введённых скоростей
			{
				cerr << "Attention! vmin = " << vmin << " > vmax = " << vmax << " in file: " << name_of_file
					 << " in line: " << i + 2 << endl;
				exit(-3);
			}
			
			i++;
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
			cerr << "Attention! " << "The 'LAND flag' is not found among points in " << name_of_file << endl;
			exit(-3);
		}
		if (k < checkPoints.size() - 1) //Проверка, чтобы не было более одной точки с флагом посадки
		{
			cerr << "Attention! " << "In " << name_of_file << " 'LAND flag' occurs more than one time";
			exit(-3);
		}
		
		CheckPointFile.close();
		
	}