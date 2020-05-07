//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_READ_SCHEME_H
#define TIMES_AND_PLANES_READ_SCHEME_H

#include <string>
#include <vector>
#include <Fields of Zone/Cycle.h>
#include "Fields of Zone/CheckPoint.h"
#include "Fields of Zone/Scheme.h"

using namespace std;


void
Read_Scheme(const string &name_of_file, vector<CheckPoint> &checkPoints, vector<Scheme> &schemes, vector<Cycle> &cycles);

#endif