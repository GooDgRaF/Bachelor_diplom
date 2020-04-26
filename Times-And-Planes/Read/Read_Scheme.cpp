//
// Created by Антон on 10.02.2020.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Functions/Function_Find-InVector.h>
#include "Maps.h"
#include "Scheme.h"
#include "Functions/Function_OpenFile.h"
#include "Functions/Function_Find-InMap.h"
#include "Functions/Function_Fill-scheme.h"

using namespace std;

void Read_Scheme(const string &name_of_file, vector<CheckPoint> &checkPoints, vector<Scheme> &schemes)
	{
		size_t k;
		
		ifstream SchemeFile;
		
		openFile(name_of_file, SchemeFile);
		
		SchemeFile >> k; //Первым идёт количество схем
		
		schemes.resize(k);
		
		/*
		 * Пояснение к регулярному выражению:
		 * Всего семь групп захвата
		 * NameA (POINT1)(POINT12 POINT13): POINT1 POINT2 Str(POINT12 POINT13) POINT3 POINT4 POINT5 /Str POINT12
		 * 1) Название схемы [NameA]
		 * 2) Название точки начала схемы [POINT1]
		 * 3) Названия точек конца схемы [POINT12 POINT13]
		 * 4) Названия точек, предшествующих спрямлению [POINT1 POINT2]
		 * 5) Названия точек куда можно спрямляться [POINT12 POINT13]
		 * 6) Названия точек откуда можно спрямляться [POINT3 POINT4 POINT5]
		 * 7) Названия точек следующих за спрямлением [POINT12]
		 * 4,6,7) Названия образующие path [POINT1 POINT2 + POINT3 POINT4 POINT5 + POINT12]
		 * Если спрямления нет, то 5,6,7 - пустые
		 */
		
		string str;
		cmatch res;
		regex regular(
				R"((\w+)\s*\((\w+)\)\s*\(([\w\s]+)\)\s*:\s*([\w\s]+)?\s+(?:Str\(([\w\s]+)\)\s*([\w\s]+)\/Str)?\s*([\w\s]*)?)");
		int i = 0; // Счётчик, отвечающий за проход по schemes
		
		string tmp;
		getline(SchemeFile, tmp); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(SchemeFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + 2 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			try //Заполняем соответственно комментарию о регулярном выражении
			{
				schemes[i].name = res[1];
				
				pointIDtoStartSchemeID[findValueINpointNameToID(res[2])].push_back(i); //Заполняем отображение ID точки --> ID схемы, которая начинается в этой точке
				
				schemes[i].start = findValueINpointNameToID(res[2]);
				
				fillScheme(res[3], schemes[i].end);
				
				fillScheme(res[5], schemes[i].straighteningWhere);
				
				fillScheme(res[6], schemes[i].straighteningFrom);
				
				fillScheme(res[4], schemes[i].path); //Собрали точки до спрямления
				
				for (auto el : schemes[i].straighteningFrom) //Собрали точки с которых возможно спрямление
				{
					schemes[i].path.push_back(el);
				}
				
				fillScheme(res[7], schemes[i].path); //Собрали точки после спрямления
				
			}
			catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из схемы среди точек из checkPoints
			{
				cerr << "Can't find '" << ex.what() << "' in line '" << i + 2 << "' among points from Points file"
					 << endl;
				exit(-2);
			}
			
			i++;
			
		}
		
		SchemeFile.close();
		
	}
