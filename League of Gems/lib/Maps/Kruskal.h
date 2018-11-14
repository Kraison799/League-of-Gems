//
// Created by gabriel on 28/10/18.
//

#ifndef LIB_KRUSKAL_H
#define LIB_KRUSKAL_H

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

class Kruskal : public Map{
public:
    Kruskal();
    std::list<Cell*>* findPath(int iStart, int jStart, int iTarget, int jTarget);
    void getPositions(int xi,int yi,int xf, int yf) override;
private:
    Graph* graph;
    std::list<Cell*>* path;
    int xTarget;
    int yTarget;

    //se crea un arbol de expansion minima para un solo nodo objetivo. Si este cambia, se recalculara
    Graph* findMST(int iStart, int jStart, int iPlayer, int jPlayer);
};



#endif //LIB_KRUSKAL_H
