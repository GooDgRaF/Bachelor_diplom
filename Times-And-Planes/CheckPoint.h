//
// Created by Антон on 10.02.2020.
//

#ifndef TIMES_AND_PLANES_CHECKPOINT_H
#define TIMES_AND_PLANES_CHECKPOINT_H

#include <string>

using namespace std;

struct CheckPoint
{
    string Name;
    double x;
    double y;
    double z;
    double Vmin;
    double Vmax;
    int Landing_flag; // !!! bool
};

#endif //TIMES_AND_PLANES_CHECKPOINT_H
