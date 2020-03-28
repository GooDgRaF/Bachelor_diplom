//
// Created by Антон on 23.03.2020.
//

#ifndef TIMES_AND_PLANES_FLOW_H
#define TIMES_AND_PLANES_FLOW_H

#include <vector>

using namespace std;

struct Flow
{
	string name;
	int start_point;
    vector<vector<int>> graph_of_descendants; //Подграф графа Zone, заданный списками Следующий
    vector<vector<int>> graph_of_ancestors; //Подграф графа Zone, заданный списками Предшествующий
    vector<int> keys; //Массив для значений вершин после топологической сортировки
};


#endif //TIMES_AND_PLANES_FLOW_H
