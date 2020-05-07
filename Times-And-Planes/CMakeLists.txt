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
        Read/Read_CheckPoints.cpp Read/Read_CheckPoints.h
        Read/Read_Scheme.cpp Read/Read_Scheme.h
        "Fields of Zone/Scheme.h"
        Functions/Fill-scheme.cpp Functions/Fill-scheme.h
        Build/Build_Zone.cpp Build/Build_Zone.h
        Functions/Find-InVector.h
        Functions/Topologic_Sort.cpp            Functions/Topologic_Sort.h
        Zone.h        Zone.cpp
        Build/Build_Flow.cpp        Build/Build_Flow.h
        Read/Read_Flow.cpp        Read/Read_Flow.h
        "Stage -1.cpp"        "Stage -1.h"
        "Calculating times.cpp"        "Calculating times.h"
        Functions/MergeTimes.cpp Functions/MergeTimes.h
        "Measure units/Coordinate.cpp"        "Measure units/Coordinate.h"
        "Measure units/Velocity.cpp"        "Measure units/Velocity.h"
        "Measure units/Time.cpp"        "Measure units/Time.h"
        "Measure units/MeasureUnits.h"
        Read/Read_CheckPointsRegExp.cpp        Read/Read_CheckPointsRegExp.h "Fields of Zone/Cycle.h" "Functions/Calculate cycles.cpp" "Functions/Calculate cycles.h")
