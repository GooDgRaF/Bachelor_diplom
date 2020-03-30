//
// Created by Антон on 28.03.2020.
//

#include <stack>
#include "Zone.h"
#include "Build_Flow.h"


void Build_Flow(Zone &zone, Flow &flow, int start_of_flow)
{
	stack<int> st;
	st.push(start_of_flow);
	vector<bool> mark(zone.graph_of_descendants.size(), false);
	flow.keys.resize(zone.graph_of_descendants.size());
	
	while (!st.empty())
	{
		int v = st.top();st.pop();
		for (int son : zone.graph_of_descendants[v])
		{
			flow.graph_of_descendants[v].push_back(son);
			if (mark[son] == 0)
			{
				st.push(son);
				mark[son] = true;
			}
		}
		
	}


}