//
// Created by gabriel on 28/10/18.
//

#ifndef LIB_KRUSKAL_H
#define LIB_KRUSKAL_H


#include "Map.h"

class Kruskal : public Map{
public:
    void getPositions(int xi, int yi, int xf, int yf) override;
};


#endif //LIB_KRUSKAL_H
