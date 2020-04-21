//
// Created by Антон on 17.04.2020.
//

#ifndef TIMES_AND_PLANES_COORDINATE_H
#define TIMES_AND_PLANES_COORDINATE_H


#include "Time.h"

class Coordinate
{
	double ms; //В метрах
	
	static constexpr double Km2ms = 1000;
	static constexpr double NMs2ms = 1852;
	
	Coordinate(double d);

public:
	double getMs() const;
	
	double getKms() const;
	
	double getNMs() const;
	
	static Coordinate createMs(double ms);
	
	static Coordinate createKMs(double kms);
	
	static Coordinate createNMs(double nms);
	
	Coordinate operator+();
	
	Coordinate operator-();
	
};

Coordinate operator+(const Coordinate &a, const Coordinate &b);

Coordinate operator-(const Coordinate &a, const Coordinate &b);

Coordinate operator*(const Time t, const Velocity v);

Coordinate operator*(const Velocity v, const Time t);

Coordinate pow(Coordinate x, int a);

Coordinate sqrt(Coordinate x);


#endif //TIMES_AND_PLANES_COORDINATE_H
