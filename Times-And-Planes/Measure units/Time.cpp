//
// Created by Антон on 19.04.2020.
//

#include <cmath>
#include "Time.h"
#include "Coordinate.h"
#include "Velocity.h"


Time::Time(double d)
	{
		time = d;
	}

double Time::getTsec() const
	{
		return time;
	}

double Time::getTmin() const
	{
		return time / min2sec;
	}

double Time::getTmin(const double &round_to) const
	{
		return round(time / min2sec * round_to) / round_to;
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
		return {time};
	}

Time Time::operator-()
	{
		return {-time};
	}

std::ostream &operator<<(std::ostream &out, const Time &t)
	{
		//out << t.time << " sec";
		out << t.getTmin(100) << " min";
		return out;
	}

Time operator/(const Coordinate &x, const Velocity &v)
	{
		return Time::createTsec(x.getMs() / v.getVm_s());
	}

Time operator+(const Time &t0, const Time &t1)
	{
		return Time::createTsec(t0.getTsec() + t1.getTsec());
	}

Time operator-(const Time &t0, const Time &t1)
	{
		return Time::createTsec(t0.getTsec() - t1.getTsec());
	}
