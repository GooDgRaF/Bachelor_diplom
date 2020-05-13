//
// Created by Антон on 10.02.2020.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Functions/Find-InVector.h>
#include <Fields of Zone/Cycle.h>
#include "Fields of Zone/Maps.h"
#include "Fields of Zone/Scheme.h"
#include "Functions/OpenFile.h"
#include "Functions/Fill-scheme.h"

using namespace std;

void
Read_SchemeRegExp(const string &name_of_file, vector<CheckPoint> &checkPoints, vector<Scheme> &schemes, vector<Cycle> &cycles)
	{
		int i, k;
		
		ifstream SchemeFile;
		
		openFile(name_of_file, SchemeFile);
		
		SchemeFile >> i; //Первым идёт количество схем
		SchemeFile >> k; //Потом количество циклов
		
		if ((k < 0) || (i <= 0))
		{
			cerr << "Warning put the correct value for the number of schemes or cycles in " << name_of_file << endl;
			exit(-2);
		}
		
		
		schemes.resize(i);
		cycles.resize(k);
		
		/*
		 * Пояснение к регулярному выражению:
		 * Всего восемь групп захвата:
		 * NameA (POINT1)(POINT12 POINT13)(number): POINT1 POINT2 Str(POINT12 POINT13) POINT3 POINT4 POINT5 /Str POINT12
		 * 1) Название схемы [NameA]
		 * 2) Название точки начала схемы [POINT1]
		 * 3) Названия точек конца схемы [POINT12 POINT13]
		 * 4) Вспомогательная группа, количество повторений цикла
		 * 5) Названия точек, предшествующих спрямлению [POINT1 POINT2]
		 * 6) Названия точек куда можно спрямляться [POINT12 POINT13]
		 * 7) Названия точек откуда можно спрямляться [POINT3 POINT4 POINT5]
		 * 8) Названия точек следующих за спрямлением [POINT12]
		 * 5,7,8) Названия образующие path [POINT1 POINT2 + POINT3 POINT4 POINT5 + POINT12]
		 * Если цикл есть то 3,6,7,8 группа пустые
		 * Если цикла нет - 4 группа пустая
		 * Если спрямления нет, то 6,7,8 - пустые
		 */
		
		string str;
		cmatch res;
		regex regular(
				R"((\w+)\s*\(([a-z,A-Z]\w*)\)\s*(?:\(([a-z,A-Z][\w\s]*)\))?\s*(?:\((\d+)\)\s*)?:\s*([\w\s]+)?\s+(?:Str\(([\w\s]+)\)\s*([\w\s]+)\/Str)?\s*([\w\s]*)?)");
		i = 0; // Счётчик, отвечающий за проход по schemes
		k = 0; // Счётчик, отвечающий за проход по cycles
		
		string tmp;
		getline(SchemeFile, tmp); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(SchemeFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + 3 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			if ((string(res[4]).empty()) || res[4] == "LAND") //Текущая схема не цикл
			{
				try //Заполняем соответственно комментарию о регулярном выражении
				{
					for (const auto &scheme : schemes) //Проверка, чтобы две схемы с одинаковым названием не встречались
					{
						if (scheme.name == res[1])
						{
							cerr << "Attention! '" << res[1] << "' scheme occurs twice in " << name_of_file << endl;
							exit(-2);
						}
					}
					
					schemes.at(i);
					
					schemes[i].name = string(res[1]);
					
					schemes[i].start = pointNameToID.at(string(res[2]));
					
					fillScheme(string(res[3]), schemes[i].end);
					
					fillScheme(string(res[6]), schemes[i].straighteningWhere);
					
					fillScheme(string(res[7]), schemes[i].straighteningFrom);
					
					fillScheme(string(res[5]), schemes[i].path); //Собрали точки до спрямления
					
					for (auto el : schemes[i].straighteningFrom) //Собрали точки с которых возможно спрямление
					{
						schemes[i].path.push_back(el);
					}
					
					fillScheme(string(res[8]), schemes[i].path); //Собрали точки после спрямления
					
				}
				catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из схемы среди точек из checkPoints
				{
					cerr << "Can't find '" << ex.what() << "' in line '" << i + 3 << "' among points from Points file"
						 << endl;
					exit(-2);
				}
				catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
				{
					cerr << "Check in " << name_of_file << " amount of schemes, it is low" << endl;
					exit(-2);
				}
				
				if (res[4] == "LAND")
				{
					for (auto el : schemes[i].path)
					{
						checkPoints[el].landing_flag = true;
					}
				}
				i++;
			}
			else
			{
				try
				{
					cycles.at(k);
					
					cycles[k].name = string(res[1]);
					
					cycles[k].start = pointNameToID[res[2]];
					
					cycles[k].repeat = atoi(res[4].first);
					
					fillScheme(string(res[5]), cycles[k].path);
					fillScheme(string(res[8]), cycles[k].path); //Вспомогательная добавка, на случай, если нет пробела после последней точки
				}
				catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из цикла среди точек из checkPoints
				{
					cerr << "Can't find '" << ex.what() << "' in line '" << i + k + 3
						 << "' among points from Points file"
						 << endl;
					exit(-2);
				}
				catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
				{
					cerr << "Check in " << name_of_file << " amount of cycles, it is low" << endl;
					exit(-2);
				}
				
				pointIDtoStartCycleID[cycles[k].start] = k;
				
				k++;
				
			}
		}
		schemes.resize(i); //На случай если число схем, считанное из файла больше действительного их количества
		cycles.resize(k); //На случай если число циклов, считанное из файла больше действительного их количества
		
		SchemeFile.close();
		
	}
