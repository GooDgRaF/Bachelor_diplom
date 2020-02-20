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

void Read_Scheme(const string &name_of_file, vector<CheckPoint> &checkPoint, std::map<string, size_t> &pointNameToID,
                 vector<Scheme> &scheme)
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

        scheme[i] = {res[1].str(), res[2].str(), res[3].str(),
                     res[4].str() + res[6].str() + res[7].str(),
                     res[6].str(), res[5].str()};
        // scheme[i].name = ...
        // scheme[i].start = ...

        i++;

    }

    SchemeFile.close();


}
