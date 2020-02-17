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



void Read_CheckPoints(const std::string &name_of_file, std::vector<CheckPoint> &CheckPoints,
                      std::map<string, size_t> &pointNameToID)
{
    size_t k = 0;

    ifstream CheckPointFile;

    CheckPointFile = openFile(name_of_file);

    CheckPointFile >> k;

    CheckPoints.resize(k);

    for(size_t i = 0; i < k; i++)
    {
        CheckPointFile >> CheckPoints[i].Name >>
        CheckPoints[i].x >> CheckPoints[i].y >> CheckPoints[i].z >>
        CheckPoints[i].Vmin >> CheckPoints[i].Vmax >> CheckPoints[i].Landing_flag;
        pointNameToID[CheckPoints[i].Name] = i;
    }

    CheckPointFile.close();

}

