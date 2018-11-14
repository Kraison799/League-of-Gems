//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_LIBRARY_H __attribute__((visibility("default")));
#define LIB_LIBRARY_H

#include "Minions/Minion.h"
#include "Minions/Structure.h"
#include "Maps/Map.h"

extern "C"{
    //Funciones de Mapa
    LIB_LIBRARY_H Map* getMap(int level);
    LIB_LIBRARY_H void SendPositions(Map* map, int xi, int yi, int xf, int yf);
    LIB_LIBRARY_H int GetListLenght(Map* map);
    LIB_LIBRARY_H int GetListPosition(Map* map);
    //Funciones de Minions
    LIB_LIBRARY_H Minion* getMinion(int index);
    LIB_LIBRARY_H void atkM(Minion* target);
    LIB_LIBRARY_H void atkMM(Minion* target, Minion* attacker);
    LIB_LIBRARY_H void atkMS(Minion* target, Structure* attacker);
    LIB_LIBRARY_H void atkS(Structure* target);
    LIB_LIBRARY_H void atkSM(Structure* target, Minion* attacker);
    LIB_LIBRARY_H void heal(Minion* target);
    LIB_LIBRARY_H void fury(Minion* target);
}

#endif //LIB_LIBRARY_H
