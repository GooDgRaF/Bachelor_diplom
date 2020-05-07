//
// Created by Антон on 05.05.2020.
//

#ifndef TIMES_AND_PLANES_CYCLE_H
#define TIMES_AND_PLANES_CYCLE_H


#include <string>
#include <vector>
#include <Measure units/Time.h>

using namespace std;

struct Cycle
{
	string nameS; //Название точки старта цикла
	string nameF; //Название точки окончания цикла
	vector<int> path; //Маршрут цикла
	int repeat; //Количество повторений цикла
	Time Tmin = Time::createTsec(0);
	Time Tmax = Time::createTsec(0);
};


#endif //TIMES_AND_PLANES_CYCLE_H
