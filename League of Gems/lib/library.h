//
// Created by gabriel on 21/10/18.
//

#ifndef LIB_LIBRARY_H __attribute__((visibility("default")));
#define LIB_LIBRARY_H

#include "Minions/Minion.h"
#include "Minions/Structure.h"

extern "C"{
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
