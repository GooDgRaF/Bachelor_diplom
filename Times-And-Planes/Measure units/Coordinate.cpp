//
// Created by Антон on 17.04.2020.
//

#include "Coordinate.h"

double Coordinate::getMs() const
	{
		return ms;
	}

double Coordinate::getKms() const
	{
		return Kms;
	}

double Coordinate::getNMs() const
	{
		return NMs;
	}

Coordinate Coordinate::createMs(double ms)
	{
		return {ms};
	}

Coordinate::Coordinate(double d)
	{
		ms = d; Kms = d / Km2ms; NMs = d / NMs2ms;
	}

Coordinate Coordinate::createKMs(double kms)
	{
		return {kms * Km2ms};
	}

Coordinate Coordinate::createNMs(double nms)
	{
		return {nms * NMs2ms};
	}
