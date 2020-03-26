//
// Created by Антон on 24.03.2020.
//

#include "Topologic_Sort.h"
#include <iostream>

void topologicalSort(vector<vector<int>> &graph, vector<int> &keys)
{
    keys.resize(graph.size());
    int number = 0;
    vector<int> DegIn(graph.size(), 0);
    stack<int> ctek;

    for(auto & sons : graph)  //Ребра из v в w
    {
        for(int w : sons)
        {
            DegIn[w] = DegIn[w] + 1;
        }
    }

    for (int i = 0;i < graph.size(); i++)
    {
        if (DegIn[i] == 0)
        {
            ctek.push(i);
        }
    }
    while (!ctek.empty())
    {
        int v;
        v = ctek.top();ctek.pop();
        keys[v] = number; number++;
        for (int w : graph[v])
        {
            DegIn[w]--;
            if (DegIn[w] == 0) {ctek.push(w);}
        }
    }



    cout << "Graph successfully sorted";

}

