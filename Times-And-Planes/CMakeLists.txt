cmake_minimum_required(VERSION 3.15)
project(Times_And_Planes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Times_And_Planes
        main.cpp
        "Fields of Zone/CheckPoint.h"
        "Fields of Zone/Flow.h"
        Functions/OpenFile.cpp Functions/OpenFile.h
        "Fields of Zone/Maps.h" "Fields of Zone/Maps.cpp"
        Read/Read_SchemeRegExp.cpp Read/Read_SchemeRegExp.h
        "Fields of Zone/Scheme.h"
        Functions/Fill-scheme.cpp Functions/Fill-scheme.h
        Build/Build_graph_of_Zone.cpp Build/Build_graph_of_Zone.h
        Functions/Find-InVector.h
        Functions/Topologic_Sort.cpp            Functions/Topologic_Sort.h
        Zone.h        Zone.cpp
        Build/Build_Flow.cpp        Build/Build_Flow.h
        "Stage -1.cpp"        "Stage -1.h"
        "Functions/Calculate times.cpp"        "Functions/Calculate times.h"
        Functions/MergeTimes.cpp Functions/MergeTimes.h
        "Measure units/Coordinate.cpp"        "Measure units/Coordinate.h"
        "Measure units/Velocity.cpp"        "Measure units/Velocity.h"
        "Measure units/Time.cpp"        "Measure units/Time.h"
        "Measure units/MeasureUnits.h"
        Read/Read_CheckPointsRegExp.cpp        Read/Read_CheckPointsRegExp.h
        "Fields of Zone/StandardScheme.h"
        "Functions/Calculate standard scheme.cpp"        "Functions/Calculate standard scheme.h"
        Read/Read_FlowRegExp.cpp        Read/Read_FlowRegExp.h)
