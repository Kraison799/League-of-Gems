//
// Created by gabriel on 21/10/18.
//

#include "library.h"
#include "Debug.h"
#include "Maps/Bresenham.h"
#include "Maps/AStar.h"
#include "Maps/Djikstra.h"
#include <iostream>
//Funciones de Mapa
LIB_LIBRARY_H Map* getMap(int level){

    if (level == 1){
        Debug::Log("using SightLine",Color::Blue);
        std::cout<< "printing SightLine" <<endl;
        return new Bresenham;
    }
    else if(level == 2){
        Debug::Log("using Djikstra",Color::Blue);
        std::cout<< "printing Djikstra" <<endl;
        return new Djikstra;
    }
    else if(level == 3){
        Debug::Log("using Kruskal",Color::Blue);
        std::cout<< "printing Kruskal" <<endl;
        return new AStar;
    }
    else if(level == 4){
        Debug::Log("using Prim",Color::Blue);
        std::cout<< "printing Prim" <<endl;
        return new Prim;
    }
    else {
        Debug::Log("using AStar",Color::Blue);
        std::cout<< "printing AStar" <<endl;
        return new AStar;
    }
}
LIB_LIBRARY_H void SendPositions(Map* map, int xi, int yi, int xf, int yf){
    map->getPositions(xi,yi,xf,yf);
}
LIB_LIBRARY_H int GetListLenght(Map* map){
    Debug::Log("getting list lenght...");
    std::cout<< "sending list lenght..." <<endl;
    return map->sendListLenght();
}
LIB_LIBRARY_H int GetListPosition(Map* map){
    Debug::Log("getting positions...");
    return map->sendpositionxory();
}
//Funciones de Minions
LIB_LIBRARY_H Minion* getMinion(int index) {}

LIB_LIBRARY_H void atkM(Minion* target) {}

LIB_LIBRARY_H void atkMM(Minion* target, Minion* attacker) {}

LIB_LIBRARY_H void atkMS(Minion* target, Structure* attacker) {}

LIB_LIBRARY_H void atkS(Structure* target) {}

LIB_LIBRARY_H void atkSM(Structure* target, Minion* attacker) {}