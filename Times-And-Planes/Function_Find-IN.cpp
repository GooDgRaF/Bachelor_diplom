//
// Created by Антон on 09.03.2020.
//
#include <map>
#include "Function_Find-IN.h"

extern map<string, int> pointNameToID;

int findValueINpointNameToID (const string& Key)
{
    if (pointNameToID.find(Key) == pointNameToID.end()) //Не удачный поиск, сообщить об ошибке
    {
        throw  Key;
    }
    return pointNameToID.find(Key)->second;
}
