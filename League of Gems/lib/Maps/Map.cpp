#include "Map.h"
#include "../Debug.h"

//
// Created by gabriel on 21/10/18.
//
int Map::sendpositionxory() {
    int pos = positions.get(0);
    positions.delFirst();
    Debug::Log("Position X or Y: ");
    Debug::Log(pos);
    return pos;
}

void Map::getPositions(int xi, int yi, int xf, int yf) {

}
int Map::sendListLenght(){
    Debug::Log("List Lenght: ");
    Debug::Log(positions.size);
    return positions.size;
}
#include "Map.h"
