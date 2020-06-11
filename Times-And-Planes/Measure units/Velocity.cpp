//
// Created by Антон on 19.04.2020.
//

#include "Velocity.h"
#include "Coordinate.h"
#include "MeasureUnits.h"


Velocity::Velocity(double d)
	{
		velocity_m_s = d;
	}

double Velocity::getVm_s() const
	{
		return velocity_m_s;
	}

double Velocity::getVkm_h() const
	{
		return velocity_m_s * m_s2km_h;
	}

double Velocity::getVnm_h() const
	{
		return velocity_m_s * m_s2nm_h;
	}

Velocity Velocity::createVm_s(double m_s)
	{
		return {m_s};
	}

Velocity Velocity::createVkm_h(double km_h)
	{
		return {km_h / m_s2km_h};
	}

Velocity Velocity::createVnm_h(double nm_h)
	{
		return {nm_h / m_s2nm_h};
	}

Velocity operator/(const Coordinate &x, const Time &t)
	{
		return Velocity::createVm_s(x.getMs() / t.getTsec());
	}

Velocity operator+(const Velocity &v, const Velocity &w)
	{
		return Velocity::createVm_s(v.getVm_s() + w.getVm_s());
	}

Velocity operator-(const Velocity &v, const Velocity &w)
	{
		return Velocity::createVm_s(v.getVm_s() - w.getVm_s());
	}

Velocity operator*(const double &a, const Velocity &v)
	{
		return Velocity::createVm_s(a * v.getVm_s());
	}

Velocity operator*(const Velocity &v, const double &a)
	{
		return Velocity::createVm_s(v.getVm_s() * a);
	}
