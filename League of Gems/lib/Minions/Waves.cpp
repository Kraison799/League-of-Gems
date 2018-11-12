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

void Waves::newWave() {
    List<Minion> nMinions;
    Minion best;
    best = this->getBest(tank);
    for (int counter = 0; counter < 16; counter++) {
        minion =  Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, tank);
        nMinions.add(minion);
    }
    best = this->getBest(melee);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, melee);
        nMinions.add(minion);
    }
    best = this->getBest(ranged);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, ranged);
        nMinions.add(minion);
    }
    best = this->getBest(mage);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, mage);
        nMinions.add(minion);
    }
    this->minions.delAll();
    for (int counter = 0; counter < 64; counter++) {
        this->minions.add(nMinions.get(counter));
    }
    nMinions.delAll();
    free(nMinions);
}
Minion Waves::getBest(types type) {
    Minion best;
    int c;
    if (type == tank) {
        c = 0;
    } else if (type == melee) {
        c = 16;
    } else if (type == ranged) {
        c = 32;
    } else if (type == mage) {
        c = 48;
    }
    for (int i = c; c < c + 16; i++) {
        if (best.getDmgTaken() < this->minions.get(i).getDmgTaken() && best.getDmgDone() > this->minions.get(c).getDmgDone()) {
            best = this->minions.get(i);
        }
    }
    return best;
}

Minion Waves::getMinion(int index) {
    return this->minions.get(index);
}
List<Minion> Waves::getMinions() {
    return this->minions;
}