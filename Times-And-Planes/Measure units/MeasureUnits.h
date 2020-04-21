//
// Created by Антон on 21.04.2020.
//

#ifndef TIMES_AND_PLANES_MEASUREUNITS_H
#define TIMES_AND_PLANES_MEASUREUNITS_H

#include "Coordinate.h"
#include "Time.h"
#include "Velocity.h"

Velocity operator/(const Coordinate &x, const Time &t);

Time operator/(const Coordinate &x, const Velocity &v);

Time operator+(const Time &t0, const Time &t1);

Time operator-(const Time &t0, const Time &t1);

Coordinate operator+(const Coordinate &a, const Coordinate &b);

Coordinate operator-(const Coordinate &a, const Coordinate &b);

Coordinate operator*(const Time &t, const Velocity &v);

Coordinate operator*(const Velocity &v, const Time &t);

Coordinate pow(Coordinate x, int a);

Coordinate sqrt(Coordinate x);

#endif //TIMES_AND_PLANES_MEASUREUNITS_H
