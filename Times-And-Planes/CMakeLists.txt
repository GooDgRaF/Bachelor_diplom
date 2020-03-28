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
        Read_/Read_CheckPoints.cpp Read_/Read_CheckPoints.h
        Read_/Read_Scheme.cpp Read_/Read_Scheme.h
        Scheme.h Functions/Function_Find-InMap.cpp Functions/Function_Find-InMap.h
        Functions/Function_Fill-scheme.cpp      Functions/Function_Fill-scheme.h
        Build_/Build_Zone.cpp                   Build_/Build_Zone.h
        Functions/Function_Find-InVector.h
        Functions/Topologic_Sort.cpp            Functions/Topologic_Sort.h
        Zone.h
        Build_/Build_Flow.cpp                   Build_/Build_Flow.h
        Read_/Read_Flow.cpp                     Read_/Read_Flow.h)
