cmake_minimum_required(VERSION 3.12)
project(lib)

set(CMAKE_CXX_STANDARD 17)

add_library(lib SHARED library.cpp library.h
        ADT/List.cpp
        ADT/List.h Maps/Djikstra.cpp
        Maps/Djikstra.h Maps/Map.cpp Maps/Map.h)