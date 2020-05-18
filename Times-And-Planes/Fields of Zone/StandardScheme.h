//
// Created by Антон on 05.05.2020.
//

#ifndef TIMES_AND_PLANES_STANDARDSCHEME_H
#define TIMES_AND_PLANES_STANDARDSCHEME_H


#include <string>
#include <vector>
#include <Measure units/Time.h>

using namespace std;

struct StandardScheme
{
	string name;
	int start; //ID точки начала и конца стандартной схемы
	int second; //ID точки начала обратного плеча стандартной схемы
	int third; //ID точки конца обратного плеча стандартной схемы
	int repeat; //Количество повторений стандартной схемы
	Time Tmin = Time::createTsec(0);
	Time Tmax = Time::createTsec(0);
};


#endif //TIMES_AND_PLANES_STANDARDSCHEME_H
