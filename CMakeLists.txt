cmake_minimum_required(VERSION 3.26)
project(kNN)

set(CMAKE_CXX_STANDARD 17)

add_executable(kNN main.cpp
        DataStructure/DataPoint.h
        Distance/DistanceCalculator.h
        KNearestNeighbor/KNearestNeighbor.h)
