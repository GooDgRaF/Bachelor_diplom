//
// Created by Антон on 10.02.2020.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Scheme.h"
#include "Function_OpenFile.h"

using namespace std;

extern map<string, int> pointNameToID;
extern map<int, int> pointIDtoStartSchemeID;

void Read_Scheme(const string &name_of_file, vector<CheckPoint> &checkPoint, vector<Scheme> &scheme)
{
    size_t k;

    ifstream SchemeFile;

    SchemeFile = openFile(name_of_file);

    SchemeFile >> k;

    scheme.resize(k);

    string str;
    cmatch res;
    regex regular(R"((\w+)\s*\((\w+)\)\s*\(([\w\s]+)\)\s*:\s*([\w\s]+)?\s+(?:Str\(([\w\s]+)\)\s*([\w\s]+)\/Str)?\s*([\w\s]*)?)");
    int i = 0;

    string tmp;
    getline(SchemeFile,tmp); //прочитать пустую строчку чтобы не мешалась

    while (getline(SchemeFile,str))
    {
        regex_match(str.c_str(), res, regular);
                

         scheme[i].name = res[1];

         pointIDtoStartSchemeID[pointNameToID.find(res[1])->second] = i;

         scheme[i].start = pointNameToID.find(res[2])->second;
         scheme[i].end = pointNameToID.find(res[3])->second;

         stringstream ssWhere(res[5]);
         string s5;
         while (ssWhere >> s5)
         {
             scheme[i].straighteningWhere.push_back(pointNameToID.find(s5)->second);
         }

         stringstream ssFrom(res[6]);
         string s6;
         while (ssFrom >> s6)
         {
             scheme[i].straighteningFrom.push_back(pointNameToID.find(s6)->second);
         }

         stringstream ssMid1(res[4]);
         stringstream ssMid2(res[6]);
         stringstream ssMid3(res[7]);
         string sm1, sm2, sm3;
         while (ssMid1 >> sm1)
         {
             scheme[i].middle.push_back(pointNameToID.find(sm1)->second);
         }
         while (ssMid2 >> sm2)
         {
             scheme[i].middle.push_back(pointNameToID.find(sm2)->second);
         }
         while (ssMid3 >> sm3)
         {
             scheme[i].middle.push_back(pointNameToID.find(sm3)->second);
         }

         i++;

    }

    SchemeFile.close();


}
