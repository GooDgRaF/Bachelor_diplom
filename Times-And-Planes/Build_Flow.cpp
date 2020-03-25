//
// Created by Антон on 23.03.2020.
//

#include <algorithm>
#include <iostream>
#include "Build_Flow.h"
#include "Functions/Function_Find-InVector.h"

void Build_Flow(vector<Scheme> &schemes, vector<vector<int>> &graph_of_flow)
{
    for (const auto& scheme : schemes)
    {
        int i = 0;

        if (findInVector(scheme.middle,scheme.start)) //Если начальная точка встречается среди средних, то она может быть только первой
        {
            graph_of_flow[scheme.start].push_back(scheme.middle[i+1]);
        } else graph_of_flow[scheme.start].push_back(scheme.middle[i]);

        if (findInVector(scheme.straighteningFrom,scheme.start))
        {
            for (const auto& str : scheme.straighteningWhere) //str - спрямление
            {
            graph_of_flow[scheme.start].push_back(str);
            }
        }

        for (; i < scheme.middle.size()-1; i++)
        {
            if (!findInVector(graph_of_flow[scheme.middle[i]],scheme.middle[i+1]))
            {
                graph_of_flow[scheme.middle[i]].push_back(scheme.middle[i+1]);
            }

            if (findInVector(scheme.straighteningFrom,scheme.middle[i]))
            {
                for (const auto &str : scheme.straighteningWhere)
                {
                    if (!findInVector(graph_of_flow[scheme.middle[i]],str))
                    {
                         graph_of_flow[scheme.middle[i]].push_back(str);
                    }

                }
            }
        }


    }

    cout << "Build sucsses!"<< endl;



}