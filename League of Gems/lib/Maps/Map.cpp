#include "Map.h"

//
// Created by gabriel on 21/10/18.
//
int Map::sendpositionxory() {
    int pos = positions.get(0);
    positions.delFirst();
    return pos;
}

void Map::getPositions(int xi, int yi, int xf, int yf) {

}
int Map::sendListLenght(){
    return positions.size;
}
#include "Map.h"
