//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_SCHEME_H
#define TIMES_AND_PLANES_SCHEME_H

#include <string>
#include <vector>
#include "CheckPoint.h"

struct Scheme
{
    std::string name;
    CheckPoint start;
    std::vector<CheckPoint> middle;
    std::vector<CheckPoint> straighteningFrom;
    std::vector<CheckPoint> straighteningWhere;
    CheckPoint end;
};

#endif //TIMES_AND_PLANES_SCHEME_H
