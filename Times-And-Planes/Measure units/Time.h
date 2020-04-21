//
// Created by Антон on 19.04.2020.
//

#ifndef TIMES_AND_PLANES_TIME_H
#define TIMES_AND_PLANES_TIME_H


class Time
{
	double t;
	
	static constexpr double min2sec = 60;
	
	Time(double d);

public:
	double getTsec() const;
	
	double getTmin() const;
	
	double getTmin(const double &round_to) const;
	
	static Time createTsec(double sec);
	
	static Time createTmin(double min);
	
	Time operator+();
	
	Time operator-();
	
};


#endif //TIMES_AND_PLANES_TIME_H
