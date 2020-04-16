//
// Created by Антон on 24.03.2020.
//

#include "Topologic_Sort.h"
#include <iostream>
#include <Flow.h>

void topologicalSort_of_flow(Flow &flow)
	{
		flow.keys.resize(flow.graph_of_descendants.size()+1);
		int number = 0;
		
		map<int, int> DegIn;
		for (auto &pair : flow.graph_of_descendants)
		{
			DegIn.emplace(pair.first, 0);
		} //Инициализируем отображение Точка --> полустепень захода
		
		stack<int> st;
		
		for (auto &pair : flow.graph_of_descendants)  //Заполняем отображение Точка --> полустепень захода
		{
			for (int w : pair.second)
			{
				DegIn[w] = DegIn[w] + 1;
			}
		}
		
		for (auto &pair : flow.graph_of_descendants) //Складываем на стек все вершины с нулевой полустепенью захода
		{
			if (DegIn[pair.first] == 0)
			{
				st.push(pair.first);
			}
		}
		
		while (!st.empty())
		{
			int v;
			v = st.top();
			st.pop();
			flow.keys[number] = v;
			number++;
			for (int son : flow.graph_of_descendants[v])
			{
				DegIn[son]--;
				if (DegIn[son] == 0)
				{ st.push(son); }
			}
		}
		
		
		cout << flow.name << " successfully sorted!" << endl;
		
	}

