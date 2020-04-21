cmake_minimum_required(VERSION 3.15)
project(Times_And_Planes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Times_And_Planes
        main.cpp
        CheckPoint.h
        Flow.h
        Functions/Function_OpenFile.cpp         Functions/Function_OpenFile.h
        Maps.h                                  Maps.cpp
        Read/Read_CheckPoints.cpp Read/Read_CheckPoints.h
        Read/Read_Scheme.cpp Read/Read_Scheme.h
        Scheme.h Functions/Function_Find-InMap.cpp Functions/Function_Find-InMap.h
        Functions/Function_Fill-scheme.cpp      Functions/Function_Fill-scheme.h
        Build/Build_Zone.cpp Build/Build_Zone.h
        Functions/Function_Find-InVector.h
        Functions/Topologic_Sort.cpp            Functions/Topologic_Sort.h
        Zone.h        Zone.cpp
        Build/Build_Flow.cpp        Build/Build_Flow.h
        Read/Read_Flow.cpp        Read/Read_Flow.h
        "Stage -1.cpp"        "Stage -1.h"
        "Calculating times.cpp"        "Calculating times.h"
        Functions/Function_MergeTimes.cpp        Functions/Function_MergeTimes.h
        "Measure units/Coordinate.cpp"        "Measure units/Coordinate.h"
        "Measure units/Velocity.cpp"        "Measure units/Velocity.h"
        "Measure units/Time.cpp"        "Measure units/Time.h" "Measure units/MeasureUnits.h")
