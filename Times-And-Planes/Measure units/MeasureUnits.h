//
// Created by Антон on 21.04.2020.
//

#ifndef TIMES_AND_PLANES_MEASUREUNITS_H
#define TIMES_AND_PLANES_MEASUREUNITS_H

#include <cmath>
#include "Coordinate.h"
#include "Time.h"
#include "Velocity.h"

Velocity operator/(const Coordinate &x, const Time &t); //Перегрузка операторов

Velocity operator+(const Velocity &v, const Velocity &w);

Velocity operator-(const Velocity &v, const Velocity &w);

Time operator/(const Coordinate &x, const Velocity &v);

Time operator+(const Time &t0, const Time &t1);

Time operator-(const Time &t0, const Time &t1);

Coordinate operator+(const Coordinate &a, const Coordinate &b);

Coordinate operator-(const Coordinate &a, const Coordinate &b);

Coordinate operator*(const Time &t, const Velocity &v);

Coordinate operator*(const Velocity &v, const Time &t);

Coordinate operator*(const int &a, const Coordinate &x);

Coordinate operator*(const Coordinate &x, const int &a);

Coordinate pow(Coordinate x, int a);

Coordinate sqrt(Coordinate x);

struct compLess
{
	bool operator()(const Time &t0, const Time &t1)
		{
			return (std::abs(t0.getTsec() - t1.getTsec()) >= Time::epsilon) && (t0.getTsec() < t1.getTsec());
		}
};

struct compGreater
{
	bool operator()(const Time &t0, const Time &t1)
		{
			return (std::abs(t0.getTsec() - t1.getTsec()) >= Time::epsilon) && (t0.getTsec() > t1.getTsec());
		}
};

#endif //TIMES_AND_PLANES_MEASUREUNITS_H
