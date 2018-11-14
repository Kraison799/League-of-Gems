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

    //Bresenhan
    map = getMap(1);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }

    //Djikstra
    map = getMap(2);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }
    //Kruskal
    map = getMap(3);
    SendPositions(map, 12, 3, 38, 38);
    lenght = GetListLenght(map);
    for (int i=0;i<lenght;i++){
        std::cout<< GetListPosition(map) <<std::endl;
    }
    //Prim
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
    }


    ///Waves
    Waves* wave;
    wave = getWaves();
    Minion t;
    Minion m;
    Minion r;
    Minion w;
    Structure structure;

    std::cout << "Minions: " << std::endl;
    printf("%-10i %-10i %-10i %-10i \n","Tank","Melee","Ranged","Mage");
    for (int i=0; i<16; i++) {
        t = wave->getMinion(i);
        m = wave->getMinion(i+16);
        r = wave->getMinion(i+32);
        w = wave->getMinion(i+48);
        printf("%-10i %-10i %-10i %-10i \n",t.getHP(),m.getHP(),r.getHP(),w.getHP());
        atkM(t.getPtr());
        atkMM(m.getPtr(), w.getPtr());
        atkMS(r.getPtr());
        atkS(structure.getPtr());
        atkSM(structure.getPtr(), r.getPtr());
        heal(t.getPtr());
        fury(m.getPtr());
        printf("%-10i %-10i %-10i %-10i \n",t.getHP(),m.getHP(),r.getHP(),w.getHP());
    }


    return 0;
}