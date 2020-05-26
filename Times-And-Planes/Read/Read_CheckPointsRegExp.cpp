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
		int i, k = 0;
		
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
		 * 1) - имя точки [NameP], начинается с буквы
		 * 2,3,4) - координаты x,y,z
		 * 5,6) - скорости vmin, vmax
		 * 7) - флаг посадочной полосы - LAND или пусто либо 0
		 */
		
		string str;
		cmatch res;
		regex regular(R"(([a-z,A-Z]\w*)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([-+]?[0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)\s+([0-9]*\.?[0-9]+)\s*(LAND|0)?\s*)");
		
		i = 0; //Счётчик, отвечающий за проход по chekpoints
		k = 0; //Счётчик, отвечающщий за точку с флагом LAND
		
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
			try
			{
				checkPoints.at(i); //Проверка доступа к i-ой координате вектора checkPoints
				
				x = stod(string(res[2]));
				y = stod(string(res[3]));
				z = stod(string(res[4]));
				vmin = stod(string(res[5]));
				vmax = stod(string(res[6]));
			}
			catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
			{
				cerr << "Check in " << name_of_file << " amount of points, it is low" << endl;
				exit(-2);
			}
			catch (const invalid_argument &ex) //Не бывает
			{
				cerr << "Warning! Line '" << i + 2 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			checkPoints[i].name = res[1];
			
			checkPoints[i].x = Coordinate::createMs(x);
			checkPoints[i].y = Coordinate::createMs(y); //В зависимости от исходных данных
			checkPoints[i].z = Coordinate::createMs(z);
			
			checkPoints[i].Vmin = Velocity::createVm_s(vmin); //В зависимости от исходных данных
			checkPoints[i].Vmax = Velocity::createVm_s(vmax);
			
			if (res[7] == "LAND")
			{
				checkPoints[i].landing_flag = true;
				k++;
				if (k > 1)
				{
					cerr << "Attention! in " << name_of_file << " was found more than one points with 'LAND' flag"
						 << endl;
					exit(-3);
				}
			}
			
			
			pointNameToID[checkPoints[i].name] = i;
			
			
			if (vmin > vmax) //Проверка корректности введённых скоростей
			{
				cerr << "Attention! vmin = " << vmin << " > vmax = " << vmax << " in file: " << name_of_file
					 << " in line: " << i + 2 << endl;
				exit(-3);
			}
			
			i++;
		}
		if (k == 0)
		{
			{
				cerr << "Attention! in " << name_of_file << " wasn't found no one points with 'LAND' flag" << endl;
				exit(-3);
			}
		}
		
		if (checkPoints.size() > i) //На случай если число точек считанное из файла, больше действительного их количества
		{
			checkPoints.resize(i);
		}
		
		CheckPointFile.close();
		
	}