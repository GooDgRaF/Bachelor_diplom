//
// Created by Антон on 19.04.2020.
//

#ifndef TIMES_AND_PLANES_VELOCITY_H
#define TIMES_AND_PLANES_VELOCITY_H


class Velocity
{
	double v = 0; //В м/с
	
	static constexpr double m_s2km_s = 3.6;
	static constexpr double m_s2nm_h = 1.94;
	
	Velocity(double d);

public:
	double getVm_s() const;
	
	static Velocity createVm_s(double m_s);
	
	static Velocity createVkm_h(double km_h);
	
	double getVkm_h() const;
	
	double getVnm_h() const;
	
};




#endif //TIMES_AND_PLANES_VELOCITY_H
