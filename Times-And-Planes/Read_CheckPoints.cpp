//
// Created by Антон on 10.02.2020.
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Maps.h"
#include "CheckPoint.h"
#include "Functions/Function_OpenFile.h"

using namespace std;


void Read_CheckPoints(const string &name_of_file, vector<CheckPoint> &CheckPoints)
{
    size_t k = 0;

    ifstream CheckPointFile;

    openFile(name_of_file, CheckPointFile);

    CheckPointFile >> k;

    CheckPoints.resize(k);

    for(size_t i = 0; i < k; i++)
    {
        string tmp;
        CheckPointFile >> tmp;
        try
        {
            for (const auto& el : CheckPoints)
            {
                if (el.Name == tmp)
                  throw runtime_error(tmp);
            }
        }
            catch(runtime_error &ex)
            {
                cerr << "Attention! " << ex.what() << " point occurs twice" << endl;
                exit(-3);
            }

        CheckPoints[i].Name = tmp;
        CheckPointFile >> CheckPoints[i].x >> CheckPoints[i].y >> CheckPoints[i].z >>
        CheckPoints[i].Vmin >> CheckPoints[i].Vmax;
        CheckPointFile >> tmp;
        CheckPoints[i].Landing_flag = tmp == "LAND" ;
        pointNameToID[CheckPoints[i].Name] = i;
    }

    CheckPointFile.close();

}

