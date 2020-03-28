//
// Created by Антон on 10.02.2020.
//

#include <fstream>
#include <iostream>
#include "Function_OpenFile.h"

using namespace std;

void openFile(const string &name_of_file, ifstream &openfile)
{
    openfile.open(name_of_file);

    if (openfile.is_open())
    {
        cout << "File " << name_of_file << " is open!" << endl;
    }
    else
    {
        cerr << "Error! Can't open " << name_of_file << endl;
        exit(-1) ;
    }
}