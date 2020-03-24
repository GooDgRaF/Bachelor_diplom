//
// Created by Антон on 24.03.2020.
//

#include "Function_Find-InVector.h"

bool findInVector(const vector<int> &v, const int value)
{
    return find(v.begin(), v.end(), value) != v.end();
}