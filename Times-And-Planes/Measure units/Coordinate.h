//
// Created by Антон on 17.04.2020.
//

#ifndef TIMES_AND_PLANES_COORDINATE_H
#define TIMES_AND_PLANES_COORDINATE_H


class Coordinate
{
	double ms = 0; //В метрах
	double Kms = 0; // В километрах
	double NMs = 0; // В морских милях
	
	static constexpr double ms2Kms = 1000;
	static constexpr double ms2NMs = 1852;
	
	Coordinate(double d);

public:
	double getMs() const;
	
	double getKms() const;
	
	double getNMs() const;
	
	static Coordinate createMs(double ms);
	
	static Coordinate createKMs(double kms);
	
	static Coordinate createNMs(double nms);
	
};


#endif //TIMES_AND_PLANES_COORDINATE_H
