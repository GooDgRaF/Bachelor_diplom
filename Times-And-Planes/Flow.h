//
// Created by Антон on 23.03.2020.
//

#ifndef TIMES_AND_PLANES_FLOW_H
#define TIMES_AND_PLANES_FLOW_H

#include <vector>

using namespace std;

struct Flow
{
    vector<vector<int>> graph_of_flow;
    vector<int> keys; //Массив для значений вершин после топологической сортировки
};


#endif //TIMES_AND_PLANES_FLOW_H
