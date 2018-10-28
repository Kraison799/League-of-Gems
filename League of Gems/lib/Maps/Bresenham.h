//
// Created by gabriel on 28/10/18.
//

#ifndef LIB_BRESENHAM_H
#define LIB_BRESENHAM_H


#include "Map.h"

class Bresenham : public Map{
public:
    void getPositions(int xi, int yi, int xf, int yf) override;
};


#endif //LIB_BRESENHAM_H
