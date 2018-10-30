//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_MAP_H
#define LIB_MAP_H


#include "../ADT/List.h"

class Map {

public:
    List<int> positions;  //  [X1,Y1,X2,Y2,X3,...,Yn]
    virtual int sendpositionxory();
    virtual void getPositions(int xi, int yi, int xf, int yf);//Necesita Override
    virtual int sendListLenght();
};


#endif //LIB_MAP_H
