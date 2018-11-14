//
// Created by gabriel on 27/10/18.
//

#include <iostream>
#include "library.h"
#include "Maps/Map.h"
#include "Minions/Waves.h"
#include "ADT/List.h"


int main(){

    Map* map;
    int lenght;
    /*
    //Bresenhan
    map = getMap(1);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }
    //Prim
    map = getMap(2);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }*/
    //Djikstra
    map = getMap(3);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }/*
    //Kruskal
    map = getMap(4);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }
    //A-Star
    map = getMap(5);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }*/

    /*
     * Tengo que guardar el elemento de la lista en una variable i despues meter la variable a la lista.
    Waves waves;
    Minion minion = waves.getMinions().get(5);
    cout << waves.getMinions().get(5).getHP() << std::endl;
    cout << minion.getHP() << std::endl;
    cout << minion.getDmg(35) << std::endl;
    cout << minion.getHP() << std::endl;
    waves.getMinions().edit(minion,5);
    cout << waves.getMinions().get(5).getHP();*/

    return 0;
}