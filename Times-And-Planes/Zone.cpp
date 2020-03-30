//
// Created by Антон on 29.03.2020.
//
#include <iostream>
#include "Zone.h"
#include "Maps.h"

using namespace std;


int Zone::Index_of(vector<int> &v, int a)
	{
		return distance(v.begin(), find(v.begin(), v.end(), a));
	}

void Zone::print_flows_keys()
	{
		for (auto &flow : flows)
		{
			cout << flow.name << ": ";
			for (auto item : flow.keys)
			{
				cout << item << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}


void Zone::print_key_of_flow(int number_of_flow)
	{
		for (auto item : flows[number_of_flow].keys)
		{
			cout << item << "  ";
		}
		cout << endl << endl;
		
	}


void Zone::print_as_string()
	{
		for (int i = 0; i < graph_of_descendants.size(); ++i)
		{
			cout << checkPoints[i].Name << " --> ";
			for (auto el : graph_of_descendants[i])
			{
				cout << checkPoints[el].Name << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

void Zone::print_as_int()
	{
		for (int i = 0; i < graph_of_descendants.size(); ++i)
		{
			cout << pointNameToID[checkPoints[i].Name] << " --> ";
			for (auto el : graph_of_descendants[i])
			{
				cout << pointNameToID[checkPoints[el].Name] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

void Zone::print_flows_as_string()
	{
		for (auto &flow : flows)
		{
			cout << flow.name << ": " << endl;
			for (auto &vertex : flow.graph_of_descendants)
			{
				cout << checkPoints[vertex.first].Name << " --> ";
				for (auto el : vertex.second)
				{
					cout << checkPoints[el].Name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
		
	}

void Zone::print_flows_as_string(bool sort)
	{
		if (sort == true)
		{
			cout << "SORTED" << endl;
			for (auto &flow : flows)
			{
				cout << flow.name << ": " << endl;
				for (int key : flow.keys)
				{
					cout << checkPoints[key].Name << " --> ";
					for (auto &el : flow.graph_of_descendants[key])
					{
						cout << checkPoints[el].Name << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;
		}
		else
		{
			print_flows_as_string();
		}
	}


