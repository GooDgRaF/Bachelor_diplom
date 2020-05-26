//
// Created by Антон on 12.05.2020.
//

#include "Read_FlowRegExp.h"
#include <fstream>
#include <iostream>
#include <regex>
#include "Fields of Zone/Flow.h"
#include "Functions/OpenFile.h"
#include "Fields of Zone/Maps.h"

void Read_FlowRegExp(const string &name_of_file, vector<Flow> &flows)
	{
		int i;
		
		ifstream FlowsFile;
		
		openFile(name_of_file, FlowsFile);
		
		FlowsFile >> i; //Первым лежит количество потоков
		
		if (i <= 0)
		{
			cerr << "Warning put the correct value for the number of flows in " << name_of_file << endl;
			exit(-2);
		}
		
		flows.resize(i);
		
		/*
		 * NameFlow Name1
		 *
		 * Пояснение к регулярному выражению:
		 * Всего 2 группы захвата, согласно формату:
		 * 1 - имя потока [NameFlow]
		 * 2 - имя первой точки потока [Name1]
		 */
		
		string str;
		cmatch res;
		regex regular(R"((\w+)\s+(\w+)\s*)");
		
		i = 0; // Счётчик, отвечающий за проход по flows
		
		string tmp;
		getline(FlowsFile, tmp); //прочитать пустую строчку чтобы не мешалась
		
		while (getline(FlowsFile, str))
		{
			if (!regex_match(str.c_str(), res, regular))
			{
				cerr << "Warning! Line '" << i + 2 << "' in " << name_of_file << " doesn't follow the input format"
					 << endl;
				exit(-3);
			}
			
			for (const auto &el : flows) //Проверка, чтобы два потока с одинаковым названием не встречались
			{
				if (el.name == res[1])
				{
					cerr << "Attention! '" << res[1] << "' flow occurs twice in " << name_of_file << endl;
					exit(-3);
				}
			}
			
			try
			{
				flows.at(i); //Проверка доступа к i-ой координате вектора flows
			}
			catch (const out_of_range &ex) //Ловим ошибку о нехватке выделенного места для входных данных
			{
				cerr << "Check in " << name_of_file << " amount of flows, it is low" << endl;
				exit(-2);
			}
			
			flows[i].name = string(res[1]);
			
			try
			{
				flows[i].start_point = pointNameToID.at(string(res[2]));
			}
			catch (const out_of_range &ex) //Ловим ошибку о не обнаружении точки из потока среди точек из checkPoints
			{
				cerr << "Can't find '" << res[2] << "' among points from Points file" << endl;
				exit(-2);
			}
			i++;
		}
		
		if (flows.size() > i) //На случай если число потоков, считанное из файла больше действительного их количества
		{
			flows.resize(i);
		}
		
		FlowsFile.close();
	}