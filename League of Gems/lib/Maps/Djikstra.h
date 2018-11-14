//
// Created by gabriel on 21/10/18.
//
// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include "../ADT/List.h"
#include "Map.h"
#include "../ADT/Cell.h"
#include "../ADT/Graph.h"
#include <list>
#include <functional>
#include <queue>

#ifndef LIB_DJIKSTRA_H
#define LIB_DJIKSTRA_H

struct CompareNode : public std::binary_function<Cell*, Cell*, bool> {
    bool operator() (Cell* ComparativeCell, Cell* cellToCompare) const {
        return ComparativeCell->operator<(cellToCompare);
    }
};


class Djikstra: public Map {
public:
    Djikstra();
    std::list<Cell*>* findPath(int iStart, int jStart, int iTarget, int jTarget);
    void getPositions(int xi,int yi,int xf, int yf) override;

private:
    Graph* graph;
    static int INF;


    static void setDistanceInfinite(Graph *graph);

};

#endif //LIB_DJIKSTRA_H
