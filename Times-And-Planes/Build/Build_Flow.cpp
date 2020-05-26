//
// Created by Антон on 28.03.2020.
//

#include <stack>
#include <iostream>
#include "Zone.h"


void Build_Flow(Zone &zone, Flow &flow)
	{
		int start_of_flow = flow.start_point;
		
		flow.times[start_of_flow].push_back({Time::createTsec(0),
											 Time::createTsec(0)}); //Выставляем начальной точке потока времена по нулям
		
		stack<int> st;
		st.push(start_of_flow);
		vector<bool> mark(zone.graph_of_descendants.size(), false);
		
		while (!st.empty())
		{
			int v = st.top();
			st.pop();
			
			for (int son : zone.graph_of_descendants[v])
			{
				flow.graph_of_descendants[v].push_back(son);
				if (!mark[son]) //Если сын ещё не посещён
				{
					st.push(son);
					mark[son] = true;
				}
			}
			
		}
		
		for (auto &pair : flow.graph_of_descendants) //Собираем граф списками Предшественник
		{
			for (auto el : pair.second)
				flow.graph_of_ancestors[el].push_back(pair.first);
		}
		
		cout << "Build " << flow.name << " successes!" << endl;
	}