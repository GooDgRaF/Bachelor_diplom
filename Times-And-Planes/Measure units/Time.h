//
// Created by Антон on 19.04.2020.
//

#ifndef TIMES_AND_PLANES_TIME_H
#define TIMES_AND_PLANES_TIME_H
#include "iostream"

class Time
{
	double time_sec; //В секундах
	
	Time(double d);

public:
	static constexpr double min2sec = 60;
	
	static constexpr double epsilon = 0.0001; //Точность сравнения
	
	double getTsec() const;
	
	double getTsec(const double &round_to) const;
	
	double getTmin() const;
	
	double getTmin(const double &round_to) const;
	
	static Time createTsec(double sec);
	
	static Time createTmin(double min);
	
	Time operator+();
	
	Time operator-();
	
	friend std::ostream& operator<<(std::ostream &out, const Time &t);
	
	
};


#endif //TIMES_AND_PLANES_TIME_H
