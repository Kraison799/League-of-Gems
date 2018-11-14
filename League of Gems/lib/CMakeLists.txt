cmake_minimum_required(VERSION 3.12)
project(lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(lib main.cpp library.cpp library.h
#add_library(lib SHARED library.cpp library.h
        ADT/List.cpp
        ADT/List.h Maps/Djikstra.cpp
        Maps/Djikstra.h Maps/Map.cpp Maps/Map.h Maps/AStar.cpp Maps/AStar.h Debug.cpp Debug.h Maps/Bresenham.cpp Maps/Bresenham.h Maps/Kruskal.cpp Maps/Kruskal.h Maps/Prim.cpp Maps/Prim.h ADT/Cell.cpp ADT/Cell.h ADT/Graph.cpp ADT/Graph.h)
