//
// Created by Антон on 10.02.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "CheckPoint.h"
#include "Function_OpenFile.h"

using namespace std;

extern map<string, int> pointNameToID;

void Read_CheckPoints(const string &name_of_file, vector<CheckPoint> &CheckPoints)
{
    size_t k = 0;

    ifstream CheckPointFile;

    CheckPointFile = openFile(name_of_file);

    CheckPointFile >> k;

    CheckPoints.resize(k);

    for(size_t i = 0; i < k; i++)
    {
        string tmp;
        CheckPointFile >> CheckPoints[i].Name >>
        CheckPoints[i].x >> CheckPoints[i].y >> CheckPoints[i].z >>
        CheckPoints[i].Vmin >> CheckPoints[i].Vmax;
        CheckPointFile >> tmp;
        CheckPoints[i].Landing_flag = tmp == "LAND" ;
        pointNameToID[CheckPoints[i].Name] = i;
    }

    CheckPointFile.close();

}

