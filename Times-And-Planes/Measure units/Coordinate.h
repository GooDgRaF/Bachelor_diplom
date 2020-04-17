//
// Created by Антон on 17.04.2020.
//

#ifndef TIMES_AND_PLANES_COORDINATE_H
#define TIMES_AND_PLANES_COORDINATE_H


class Coordinate
{
	double ms; //В метрах
	double Kms; // В километрах
	double NMs; // В морских милях

public:
	double getMs() const;
	
	double getKms() const;
	
	double getNMs() const;
	
};


#endif //TIMES_AND_PLANES_COORDINATE_H
