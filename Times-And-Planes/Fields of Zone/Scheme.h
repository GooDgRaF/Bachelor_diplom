//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_SCHEME_H
#define TIMES_AND_PLANES_SCHEME_H

#include <string>
#include <vector>
#include "CheckPoint.h"

using namespace std;

struct Scheme
{
    string name;
    int start;
    vector<int> end;
    vector<int> path;
    vector<int> straighteningFrom;
    vector<int> straighteningWhere;
    
};

#endif //TIMES_AND_PLANES_SCHEME_H
