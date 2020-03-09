cmake_minimum_required(VERSION 3.15)
project(Times_And_Planes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Times_And_Planes
        CheckPoint.h
        Function_OpenFile.cpp
        Function_OpenFile.h
        main.cpp
        Maps.h
        Read_CheckPoints.cpp
        Read_CheckPoints.h
        Read_Scheme.cpp
        Read_Scheme.h
        Scheme.h Function_Find-IN.cpp Function_Find-IN.h Function_Fill-scheme.cpp Function_Fill-scheme.h)
