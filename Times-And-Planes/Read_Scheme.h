//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_READ_SCHEME_H
#define TIMES_AND_PLANES_READ_SCHEME_H

#include <string>
#include <vector>
#include "CheckPoint.h"
#include "Scheme.h"

using namespace std;


void Read_Scheme(const string &name_of_file, vector <CheckPoint> &checkPoint, vector <Scheme> &scheme);

#endif