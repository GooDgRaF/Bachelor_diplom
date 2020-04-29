//
// Created by Антон on 29.03.2020.
//
#include <iostream>
#include <cmath>
#include "Zone.h"
#include "Fields of Zone/Maps.h"

using namespace std;


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
			cout << checkPoints[i].name << " --> ";
			for (auto el : graph_of_descendants[i])
			{
				cout << checkPoints[el].name << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

void Zone::print_flows_as_string_des()
	{
		for (auto &flow : flows)
		{
			cout << flow.name << ": " << endl;
			for (auto &vertex : flow.graph_of_descendants)
			{
				cout << checkPoints[vertex.first].name << " --> ";
				for (auto el : vertex.second)
				{
					cout << checkPoints[el].name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
		
	}

void Zone::print_flows_as_string_des(bool sort)
	{
		if (sort == true)
		{
			cout << "SORTED" << endl;
			for (auto &flow : flows)
			{
				cout << flow.name << ": " << endl;
				for (int key : flow.keys)
				{
					cout << checkPoints[key].name << " --> ";
					for (auto &el : flow.graph_of_descendants[key])
					{
						cout << checkPoints[el].name << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;
		}
		else
		{
			print_flows_as_string_des();
		}
	}

void Zone::print_flows_as_string_anc()
	{
		for (auto &flow : flows)
		{
			cout << flow.name << ": " << endl;
			for (auto &vertex : flow.graph_of_ancestors)
			{
				cout << checkPoints[vertex.first].name << " <-- ";
				for (auto el : vertex.second)
				{
					cout << checkPoints[el].name << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
		
	}

void Zone::print_times()
	{
		for (auto &flow : flows)
		{
			cout << flow.name << ": " << endl;
			for (int key : flow.keys)
			{
				cout << checkPoints[key].name << " --> ";
				if (checkPoints[key].landing_flag == true)
				{
					for (auto &pair : flow.land_points_times[key])
					{
						cout << "[" << pair.first << ", " << pair.second << "] ";
					}
					cout << endl;
				}
				else
				{
					for (auto &pair : checkPoints[key].times)
					{
						cout << "[" << pair.first << ", " << pair.second << "] ";
					}
					cout << endl;
				}
			}
			cout << endl;
		}
		cout << endl;
	}


