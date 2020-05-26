//
// Created by Антон on 10.02.2020.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Functions/Find-InVector.h>
#include <Fields of Zone/StandardScheme.h>
#include "Fields of Zone/Maps.h"
#include "Fields of Zone/Scheme.h"
#include "Functions/OpenFile.h"
#include "Functions/Fill-scheme.h"

using namespace std;

bool stoi_bool(const string &str)
	{
		try
		{
			stoi(str);
			return true;
		}
		catch (invalid_argument &ex)
		{
			return false;
		}
	} //Истина, если строка является числом, Ложь иначе

void
Read_SchemeRegExp(const string &name_of_file, vector<CheckPoint> &checkPoints, vector<Scheme> &schemes, vector<StandardScheme> &standardSchemes)
	{
		int i, k;
		
		ifstream SchemeFile;
		
		openFile(name_of_file, SchemeFile);
		
		SchemeFile >> i; //Первым идёт количество схем
		SchemeFile >> k; //Потом количество стандартных схем
		
		if ((i <= 0) || (k < 0))
		{
			cerr << "Warning put the correct value for the number of schemes or standard schemes in " << name_of_file
				 << endl;
			exit(-2);
		}
		
		
		schemes.resize(i);
		standardSchemes.resize(k);
		
		/*
		 * Пояснение к регулярному выражению:
		 * Всего семь групп захвата:
		 * NameA (POINT1)(POINT12 POINT13 | number): POINT1 POINT2 Str(POINT12 POINT13) POINT3 POINT4 POINT5 /Str POINT12
		 * 1) Название схемы [NameA]
		 * 2) Название точки начала схемы [POINT1]
		 * 3) Названия точек конца схемы [POINT12 POINT13] или число повторений стандарной схемы
		 * 4) Названия точек, предшествующих спрямлению [POINT1 POINT2]
		 * 5) Названия точек куда можно спрямляться [POINT12 POINT13]
		 * 6) Названия точек откуда можно спрямляться [POINT3 POINT4 POINT5]
		 * 7) Названия точек следующих за спрямлением [POINT12]
		 * 4,6,7) Названия образующие path [POINT1 POINT2 + POINT3 POINT4 POINT5 + POINT12]
		 */
		
		string str;
		cmatch res;
		regex regular(
				R"((\w+)\s*(?:\((\w+)\))?\s*\(([\w\s]*|\d+)\)\s*:(?:\s*([\w\s]*)\s+(?:Str\(([\w\s]+)\)\s*([\w\s]+)\/Str)?\s*([\w\s]*)?)?)");
		i = 0; // Счётчик, отвечающий за проход по schemes
		k = 0; // Счётчик, отвечающий за проход по standardSchemes
		
		getline(SchemeFile, str); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(SchemeFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + k + 3 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			if (!stoi_bool(string(res[3]))) //Если не стандартная схема
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
					
					schemes.at(i); //Проверка доступа к i-ой координате вектора schemes
					
					if (string(res[4]).empty() && string(res[5]).empty()) //Схема из двух точек
					{
						schemes[i].name = string(res[1]);
						
						schemes[i].start = pointNameToID.at(string(res[2]));
						
						schemes[i].end.push_back(pointNameToID.at(string(res[3])));
						
						schemes[i].path.push_back(schemes[i].start);
						schemes[i].path.push_back(schemes[i].end[0]);
					}
					else //Все остальные схемы
					{
						schemes[i].name = string(res[1]);
						
						schemes[i].start = pointNameToID.at(string(res[2]));
						
						fillScheme(string(res[3]), schemes[i].end);
						
						fillScheme(string(res[5]), schemes[i].straighteningWhere);
						
						fillScheme(string(res[6]), schemes[i].straighteningFrom);
						
						fillScheme(string(res[4]), schemes[i].path); //Собрали точки до спрямления
						
						for (auto el : schemes[i].straighteningFrom) //Собрали точки с которых возможно спрямление
						{
							schemes[i].path.push_back(el);
						}
						
						fillScheme(string(res[7]), schemes[i].path); //Собрали точки после спрямления
						
					}
				}
				catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из схемы среди точек из checkPoints
				{
					cerr << "Can't find '" << ex.what() << "' in line '" << i + k + 3
						 << "' among points from Points file"
						 << endl;
					exit(-2);
				}
				catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
				{
					cerr << "Check in " << name_of_file << " amount of schemes, it is low" << endl;
					exit(-2);
				}
				i++;
			}
			else
			{
				try
				{
					standardSchemes.at(k); //Проверка доступа к i-ой координате вектора standardSchemes
					
					standardSchemes[k].name = string(res[1]);
					
					standardSchemes[k].repeat = stoi(string(res[3]));
					
					vector<int> path; //Вспомогательный вектор для заполнения полей стандартной схемы
					
					fillScheme(string(res[4]), path);
					fillScheme(string(res[7]), path); //Если нет пробела после последней точки, то нужно добавить эту точку
					
					if (path.size() != 3) //Стандартная схема описывается тремя точками
					{
						cerr << "Warning! Line '" << i + k + 3 << "' in " << name_of_file
							 << " doesn't follow the input format: the standard scheme should have three points"
							 << endl;
						exit(-3);
					}
					
					standardSchemes[k].start = path[0];
					standardSchemes[k].second = path[1];
					standardSchemes[k].third = path[2];
					
				}
				catch (const runtime_error &ex) //Ловим ошибку о не обнаружении точки из стандартной схемы среди точек из checkPoints
				{
					cerr << "Can't find '" << ex.what() << "' in line '" << i + k + 3
						 << "' among points from Points file"
						 << endl;
					exit(-2);
				}
				catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
				{
					cerr << "Check in " << name_of_file << " amount of standardSchemes, it is low" << endl;
					exit(-2);
				}
				
				startPointIDtoStSchemeID[standardSchemes[k].start] = k;
				
				k++;
				
			}
		}
		if (schemes.size() > i) //На случай если число схем, считанное из файла больше действительного их количества
		{
			schemes.resize(i);
		}
		if (standardSchemes.size() >
			k) //На случай если число стандартных схем, считанное из файла больше действительного их количества
		{
			standardSchemes.resize(k);
		}
		
		SchemeFile.close();
		
	}
