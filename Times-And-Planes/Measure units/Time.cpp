//
// Created by Антон on 19.04.2020.
//

#include <cmath>
#include "Time.h"

Time::Time(double d)
	{
		t = d;
	}

double Time::getTsec() const
	{
		return t;
	}

double Time::getTmin() const
	{
		return t / min2sec;
	}

double Time::getTmin(double round_to) const
	{
		return round(t / min2sec * round_to) / round_to;
	}

Time Time::createTsec(double sec)
	{
		return {sec};
	}

Time Time::createTmin(double min)
	{
		return {min * min2sec};
	}

Time Time::operator+()
	{
		return {t};
	}

Time Time::operator-()
	{
		return {-t};
	}

Time operator/(const Coordinate x, const Velocity v)
	{
		return Time::createTsec(x.getMs() / v.getVm_s());
	}

Time operator+(const Time t0, const Time t1)
	{
		return Time::createTsec(t0.getTsec() + t1.getTsec());
	}

Time operator-(const Time t0, const Time t1)
	{
		return Time::createTsec(t0.getTsec() - t1.getTsec());
	}
