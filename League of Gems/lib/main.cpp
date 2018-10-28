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
    int lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }
    return 0;
}