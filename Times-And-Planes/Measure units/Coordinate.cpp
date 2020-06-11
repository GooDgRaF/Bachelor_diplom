//
// Created by Антон on 17.04.2020.
//

#include "Coordinate.h"
#include "Velocity.h"
#include <cmath>

double Coordinate::getMs() const
	{
		return coordinate_ms;
	}

double Coordinate::getKms() const
	{
		return coordinate_ms / Km2ms;
	}

double Coordinate::getNMs() const
	{
		return coordinate_ms / NMs2ms;
	}

Coordinate Coordinate::createMs(double ms)
	{
		return {ms};
	}

Coordinate::Coordinate(double d)
	{
		coordinate_ms = d;
	}

Coordinate Coordinate::createKMs(double kms)
	{
		return {kms * Km2ms};
	}

Coordinate Coordinate::createNMs(double nms)
	{
		return {nms * NMs2ms};
	}

Coordinate Coordinate::operator+()
	{
		return {coordinate_ms};
	}

Coordinate Coordinate::operator-()
	{
		return {-coordinate_ms};
	}

Coordinate operator+(const Coordinate &a, const Coordinate &b)
	{
		return Coordinate::createMs(a.getMs() + b.getMs());
	}

Coordinate operator-(const Coordinate &a, const Coordinate &b)
	{
		return Coordinate::createMs(a.getMs() - b.getMs());
	}

Coordinate operator*(const Time &t, const Velocity &v)
	{
		return Coordinate::createMs(t.getTsec()*v.getVm_s());
	}

Coordinate operator*(const Velocity &v, const Time &t)
	{
		return {t*v};
	}

Coordinate pow(Coordinate x, int a)
	{
		return Coordinate::createMs(std::pow(x.getMs(),a));
	}

Coordinate sqrt(Coordinate x)
	{
		return Coordinate::createMs(std::sqrt(x.getMs()));
	}

Coordinate operator*(const Coordinate &x, const double &a)
	{
		return Coordinate::createMs(x.getMs() * a);
	}

Coordinate operator*(const double &a, const Coordinate &x)
	{
		return Coordinate::createMs(a * x.getMs());
	}
