//
// Created by Антон on 10.02.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

size_t k = 0;

struct checkPoint
{
    size_t ID;
    string Name;
    double x;
    double y;
    double z;
    double Vmin;
    double Vmax;
};

map<string,size_t> pointNameToID;

vector<checkPoint> CheckPoints;
void Read_CheckPoints(const string &name_of_file)

/** Read file and fill the CheckPoints vector and  pointNameToID map **/
{
    ifstream CheckPointFile;

    CheckPointFile.open(name_of_file);
    if (CheckPointFile.is_open())
    {
        cout << "File is open!\n";
    }
    else
    {
        cerr << "Error! Can't open file";
        exit(-1) ;
    }

    CheckPointFile >> k;

    CheckPoints.resize(k);

    for(size_t i = 0; i < k; i++)
    {
        CheckPoints[i].ID = i;
        CheckPointFile >> CheckPoints[i].Name >>
                       CheckPoints[i].x >> CheckPoints[i].y >> CheckPoints[i].z >>
                       CheckPoints[i].Vmin >> CheckPoints[i].Vmax;
        pointNameToID[CheckPoints[i].Name] = i;
    }

    CheckPointFile.close();

}

