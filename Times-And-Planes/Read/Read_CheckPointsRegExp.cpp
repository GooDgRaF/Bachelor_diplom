//
// Created by Антон on 22.04.2020.
//

#include "Read_CheckPointsRegExp.h"
#include <regex>
#include <fstream>
#include <Functions/OpenFile.h>
#include <Fields of Zone/Maps.h>

using namespace std;

void Read_CheckPointsRegExp(const std::string &name_of_file, std::vector<CheckPoint> &checkPoints)
	{
		int i = 0;
		
		ifstream CheckPointFile;
		
		openFile(name_of_file, CheckPointFile);
		
		CheckPointFile >> i; //Первым лежит значение сколько точек всего
		
		if (i <= 0)
		{
			cerr << "Warning put the correct value for the number of points in " << name_of_file << endl;
			exit(-2);
		}
		
		checkPoints.resize(i);
		
		/*
		 * Пояснение к регулярному выражению:
		 * Всего 7 групп захвата, согласно формату:
		 * NameP x y z v1 v2 land_flag
		 * 1) - имя точки [NameP]
		 * 2,3,4) - координаты x,y,z
		 * 5,6) - скорости vmin, vmax
		 * 7) - флаг посадочной полосы - LAND или пусто либо 0
		 */
		
		string str;
		cmatch res;
		regex regular(R"((\w+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)(?:\s*)(LAND|0)?)");
		
		i = 0; // Счётчик, отвечающий за проход по chekpoints
		
		string tmp;
		getline(CheckPointFile, tmp); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(CheckPointFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + 2 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			for (const auto &el : checkPoints) //Проверка, чтобы две точки с одинаковым названием не встречались
			{
				if (el.name == res[1])
				{
					cerr << "Attention! '" << res[1] << "' point occurs twice in " << name_of_file << endl;
					exit(-2);
				}
			}
			
			
			double x, y, z, vmin, vmax;
			
			x = atof(res[2].first);
			y = atof(res[3].first);
			z = atof(res[4].first);
			vmin = atof(res[5].first);
			vmax = atof(res[6].first);
			
			try
			{
				checkPoints.at(i);
			}
			catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
			{
				cerr << "Check in " << name_of_file << " amount of points, it is low" << endl;
				exit(-2);
			}
			
			
			checkPoints[i].name = res[1];
			
			checkPoints[i].x = Coordinate::createMs(x);
			checkPoints[i].y = Coordinate::createMs(y); //В зависимости от исходных данных
			checkPoints[i].z = Coordinate::createMs(z);
			
			checkPoints[i].Vmin = Velocity::createVm_s(vmin);
			checkPoints[i].Vmax = Velocity::createVm_s(vmax);
			
			checkPoints[i].landing_flag = res[7] == "LAND";
			
			pointNameToID[checkPoints[i].name] = i;
			
			
			if (vmin > vmax) //Проверка корректности введённых скоростей
			{
				cerr << "Attention! vmin = " << vmin << " > vmax = " << vmax << " in file: " << name_of_file
					 << " in line: " << i + 2 << endl;
				exit(-3);
			}
			
			i++;
		}
		
		checkPoints.resize(i); //На случай если число точек считанное из файла, больше действительного их количества
		
		
		CheckPointFile.close();
		
	}