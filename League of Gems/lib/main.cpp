//
// Created by gabriel on 27/10/18.
//

#include <iostream>
#include "library.h"
#include "Maps/Map.h"

int main(){
    //A-Star
    Map* map = getMap(5);
    SendPositions(map, 12, 3, 38, 38);
    return 0;
}