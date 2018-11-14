//
// Created by gabriel on 21/10/18.
//

#include "library.h"
#include "Debug.h"
#include "Maps/Bresenham.h"
#include "Maps/AStar.h"
#include "Maps/Djikstra.h"
#include <iostream>
#include "Maps/Prim.h"
#include "Maps/Kruskal.h"
#include "Minions/Waves.h"
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
        return new Kruskal;
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
LIB_LIBRARY_H Minion* getMinion(Waves* waves, int index) {
    Debug::Log("getting Minion pointer...");
    return waves->getMinionPtr(index);
}

LIB_LIBRARY_H void atkM(Minion* target) {
    Debug::Log("Minion attacked by Skill...");
    target->getDmg(15);
}

LIB_LIBRARY_H void atkMM(Minion* target, Minion* attacker) {
    Debug::Log("Minion attacked by Minion...");
    target->getDmg(attacker->getAtk());
}

LIB_LIBRARY_H void atkMS(Minion* target) {
    Debug::Log("Minion attacked by Structure...");
    target->getDmg(10);
}

LIB_LIBRARY_H void atkS(Structure* target) {
    Debug::Log("Structure attacked by Skill...");
    target->getDmg(10);
}

LIB_LIBRARY_H void atkSM(Structure* target, Minion* attacker) {
    Debug::Log("Structure attacked by Minion...");
    target->getDmg(attacker->getAtk());
}

LIB_LIBRARY_H void heal(Minion* target) {
    Debug::Log("Minion healed..");
    target->heal();
}

LIB_LIBRARY_H void fury(Minion* target) {
    Debug::Log("Minion fury switch...");
    target->furySwitch();
}

LIB_LIBRARY_H Structure* createStructure() {
    Debug::Log("creating Structure", Color::Blue);
    return new Structure;
}

LIB_LIBRARY_H Waves* getWaves() {
    Debug::Log("getting Waves", Color::Blue);
    return new Waves;
}