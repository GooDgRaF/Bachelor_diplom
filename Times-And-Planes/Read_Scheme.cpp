//
// Created by Антон on 10.02.2020.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Maps.h"
#include "Scheme.h"
#include "Functions/Function_OpenFile.h"
#include "Functions/Function_Find-InMap.h"
#include "Functions/Function_Fill-scheme.h"

using namespace std;

void Read_Scheme(const string &name_of_file, vector<CheckPoint> &checkPoint, vector<Scheme> &scheme)
{
    size_t k;

    ifstream SchemeFile;

    openFile(name_of_file, SchemeFile);

    SchemeFile >> k;

    scheme.resize(k);

    /*
     * Пояснение к регулярному выражению:
     * Всего семь групп захвата
     * NameA (POINT1)(POINT12 POINT13): POINT2 Str(POINT12 POINT13) POINT3 POINT4 POINT5 /Str POINT12
     * 1) Название схемы [NameA]
     * 2) Название точки начала схемы [POINT1]
     * 3) Названия точек конца схемы [POINT12 POINT13]
     * 4,6,7) Названия точек самой схемы [POINT2 + POINT3 POINT4 POINT5 + POINT12]
     * 5) Названия точек куда можно спрямляться [POINT12 POINT13]
     * 6) Названия точек откуда можно спрямляться [POINT3 POINT4 POINT5]
     */

    string str;
    cmatch res;
    regex regular(R"((\w+)\s*\((\w+)\)\s*\(([\w\s]+)\)\s*:\s*([\w\s]+)?\s+(?:Str\(([\w\s]+)\)\s*([\w\s]+)\/Str)?\s*([\w\s]*)?)");
    int i = 0;

    string tmp;
    getline(SchemeFile,tmp); //прочитать пустую строчку чтобы не мешалась

    while (getline(SchemeFile,str))
    {
        regex_match(str.c_str(), res, regular);



        try {

        scheme[i].name = res[1];

         pointIDtoStartSchemeID[findValueINpointNameToID(res[2])].push_back(i);

         scheme[i].start = findValueINpointNameToID(res[2]);

         fillScheme(res[3], scheme[i].end);

         fillScheme(res[5], scheme[i].straighteningWhere);

         fillScheme(res[6], scheme[i].straighteningFrom);

         fillScheme(res[4], scheme[i].middle);
         fillScheme(res[6], scheme[i].middle);
         fillScheme(res[7], scheme[i].middle);

        }
        catch(const runtime_error &ex)
        {
            cerr << "Can't find " << ex.what() << " in line " << i+2 << " among points" << endl;
            exit(-2);
        }

         i++;

    }

    SchemeFile.close();





}
