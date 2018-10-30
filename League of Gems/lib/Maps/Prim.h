//
// Created by gabriel on 28/10/18.
//

#ifndef LIB_PRIM_H
#define LIB_PRIM_H


#include "Map.h"

class Prim : public Map{
public:
    void getPositions(int xi, int yi, int xf, int yf) override;
};


#endif //LIB_PRIM_H
