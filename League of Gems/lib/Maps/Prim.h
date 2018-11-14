//
// Created by gabriel on 28/10/18.
//
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

#ifndef LIB_PRIM_H
#define LIB_PRIM_H

class Prim : public Map{
public:
    Prim();
    std::list<Cell*>* findPath(int iTarget, int jTarget, int iPlayer, int jPlayer);
    void getPositions(int xi,int yi,int xf, int yf) override;

private:
    Graph* graph;
    std::list<Cell*>* path;
    int xTarget;
    int yTarget;

    Graph* findMST(int iStart, int jStart, int iTarget, int jTarget);

};


#endif //LIB_PRIM_H
