//
// Created by Антон on 19.04.2020.
//

#ifndef TIMES_AND_PLANES_TIME_H
#define TIMES_AND_PLANES_TIME_H


#include "Coordinate.h"
#include "Velocity.h"

class Time
{
	double t;
	
	static constexpr double min2sec = 60;
	
	Time(const double d);

public:
	double getTsec() const;
	
	double getTmin() const;
	
	double getTmin(double round_to) const;
	
	static Time createTsec(double sec);
	
	static Time createTmin(double min);
	
	Time operator+();
	
	Time operator-();
	
};
Time operator+(const Time t0, const Time t1);

Time operator-(const Time t0, const Time t1);

Time operator/(const Coordinate x, const Velocity v);



#endif //TIMES_AND_PLANES_TIME_H
