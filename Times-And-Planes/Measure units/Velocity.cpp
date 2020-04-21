//
// Created by Антон on 19.04.2020.
//

#include "Velocity.h"

Velocity::Velocity(double d)
	{
		v = d;
	}

double Velocity::getVm_s() const
	{
		return v;
	}

double Velocity::getVkm_h() const
	{
		return v / m_s2km_s;
	}

double Velocity::getVnm_h() const
	{
		return v * m_s2nm_h;
	}

Velocity Velocity::createVm_s(double m_s)
	{
		return {m_s};
	}

Velocity Velocity::createVkm_h(double km_h)
	{
		return {km_h * m_s2km_s};
	}

Velocity operator/(const Coordinate &x, const Time &t)
	{
		return Velocity::createVm_s(x.getMs() / t.getTsec());
	}
