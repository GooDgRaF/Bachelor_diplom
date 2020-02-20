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
    string start;               // int
    string end;                 // int
    string middle;              // vector<int>
    string straighteningFrom;   // vector<int>
    string straighteningWhere;  // vector<int>
};

#endif //TIMES_AND_PLANES_SCHEME_H
