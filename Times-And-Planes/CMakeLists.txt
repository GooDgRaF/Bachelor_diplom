cmake_minimum_required(VERSION 3.15)
project(Times_And_Planes)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Times_And_Planes
        main.cpp
        Read_CheckPoints.cpp Read_CheckPoints.h
        Read_Scheme.cpp Read_Scheme.h
        CheckPoint.h
        Scheme.h
        Function_OpenFile.cpp Function_OpenFile.h)