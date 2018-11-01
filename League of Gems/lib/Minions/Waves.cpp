//
// Created by ferathor on 07/10/18.
//

#include "Waves.h"
#include "../ADT/List.h"
#include <stdlib.h>
#include <iterator>

using namespace std;

Waves::Waves() {
    Minion minion;
    for (int counter = 0; counter < 16; counter++) {
        minion =  Minion(100 + rand()%20, 20 + rand()%10, 0.40 + (float)(rand()%10)/100, tank);
        minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(80 + rand()%20, 30 + rand()%10, 0.25 + (float)(rand()%10)/100, melee);
        minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(70 + rand()%20, 40 + rand()%10, 0.20 + (float)(rand()%10)/100, ranged);
        minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(65 + rand()%20, 40 + rand()%10, 0.15 + (float)(rand()%10)/100, mage);
        minions.add(minion);
    }
}

List<Minion> Waves::getMinions() {
    return this->minions;
}