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
        Read_CheckPoints.cpp                    Read_CheckPoints.h
        Read_Scheme.cpp                         Read_Scheme.h
        Scheme.h Functions/Function_Find-InMap.cpp Functions/Function_Find-InMap.h
        Functions/Function_Fill-scheme.cpp      Functions/Function_Fill-scheme.h
        Build_Flow.cpp                          Build_Flow.h
        Functions/Function_Find-InVector.cpp    Functions/Function_Find-InVector.h
        Functions/Topologic_Sort.cpp            Functions/Topologic_Sort.h)
