//
// Created by Антон on 09.03.2020.
//

#include <sstream>
#include "Function_Fill-scheme.h"
#include "Function_Find-IN.h"


void fillScheme(const string &str, vector<int> &field)
{
    stringstream ss(str);
    string tmp;
    while (ss >> tmp)
    {
        field.push_back(findValueINpointNameToID(tmp));
    }
}