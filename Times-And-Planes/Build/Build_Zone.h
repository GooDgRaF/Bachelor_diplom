//
// Created by Антон on 23.03.2020.
//

#ifndef TIMES_AND_PLANES_BUILD_ZONE_H
#define TIMES_AND_PLANES_BUILD_ZONE_H

#include <vector>
#include "Fields of Zone/CheckPoint.h"
#include "Fields of Zone/Scheme.h"

using namespace std;

void Build_Zone(const vector<Scheme> &schemes, vector<vector<int>> &graph_of_zone);


#endif //TIMES_AND_PLANES_BUILD_ZONE_H
