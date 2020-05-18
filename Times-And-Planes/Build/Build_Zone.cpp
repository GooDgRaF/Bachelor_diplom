//
// Created by Антон on 23.03.2020.
//

#include <algorithm>
#include <iostream>
#include <Functions/Calculate standard scheme.h>
#include "Build_Zone.h"
#include "Functions/Find-InVector.h"

void Build_Zone(Zone &zone)
    {
    	
    	for (auto &cycle : zone.standardSchemes)
		{
			calcStScheme(zone.checkPoints, cycle);
		}
    	
        for (const auto &scheme : zone.schemes) //Строим граф списками Следующий
        {
            /*Идём до size - 1, так как мы соединяем дугами со следующими точками,
                 * то есть будет связь между предпоследней точкой и последней
                 * и так как схемы соединяются в нахлёст, то есть конец одной схемы это начало другой, то все хорошо.
                 */
            for (int i = 0; i < scheme.path.size() - 1; i++)
            {
                zone.graph_of_descendants[scheme.path[i]].push_back(scheme.path[i + 1]); //Соединить текущую точку со следующей

                /*
                *Если с текущей точки возможно спрямление и следующая точка не является конечной точкой спрямления
                *Пояснение ко второй части if : Пример схема типа веер. Из её предпоследней точки можно спрямиться на центральную,
                *а также можно проследовать по пути, чтобы не повторяться существует проверка
                */

                if ((findInVector(scheme.straighteningFrom, scheme.path[i])
                     && (!findInVector(scheme.straighteningWhere, scheme.path[i + 1]))))
                {
                    for (const auto &str : scheme.straighteningWhere) //Соединить текущую точку со всеми точками на которые возможно спрямление
                    {
                        zone.graph_of_descendants[scheme.path[i]].push_back(str);
                    }
                }
            }

        }

        cout << "Build zone successes!" << endl;


    }