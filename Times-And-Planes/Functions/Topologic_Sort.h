//
// Created by Антон on 24.03.2020.
//

#ifndef TIMES_AND_PLANES_TOPOLOGIC_SORT_H
#define TIMES_AND_PLANES_TOPOLOGIC_SORT_H

#include <vector>
#include <algorithm>
#include <stack>
#include <iterator>
#include <map>

using namespace std;

void topologicalSort(vector<vector<int>> &graph, vector<int> &keys);

void topologicalSort(map<int, vector<int>> &graph, vector<int> &keys);


#endif //TIMES_AND_PLANES_TOPOLOGIC_SORT_H
