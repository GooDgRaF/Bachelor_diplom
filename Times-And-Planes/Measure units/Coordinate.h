//
// Created by Антон on 17.04.2020.
//

#ifndef TIMES_AND_PLANES_COORDINATE_H
#define TIMES_AND_PLANES_COORDINATE_H


#include "Time.h"

class Coordinate
{
	double ms; //В метрах
	
	Coordinate(double d);

public:
	static constexpr double Km2ms = 1000;
	
	static constexpr double NMs2ms = 1852;
	
	double getMs() const;
	
	double getKms() const;
	
	double getNMs() const;
	
	static Coordinate createMs(double ms);
	
	static Coordinate createKMs(double kms);
	
	static Coordinate createNMs(double nms);
	
	Coordinate operator+();
	
	Coordinate operator-();
	
};


#endif //TIMES_AND_PLANES_COORDINATE_H
