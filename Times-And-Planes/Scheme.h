//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_SCHEME_H
#define TIMES_AND_PLANES_SCHEME_H

#include <string>
#include <vector>
#include "CheckPoint.h"

struct scheme
{
    std::string Name;
    checkPoint start;
    std::vector<checkPoint> middle;
    std::vector<checkPoint> straighteningFrom;
    std::vector<checkPoint> straighteningWhere;
    checkPoint end;
};

#endif //TIMES_AND_PLANES_SCHEME_H
