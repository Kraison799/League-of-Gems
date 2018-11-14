//
// Created by ferathor on 07/10/18.
//

#include "Waves.h"
#include "../ADT/List.h"
#include <stdlib.h>
#include <iterator>

using namespace std;

Waves::Waves() {
    for (int counter = 0; counter < 16; counter++) {
        Minion minion =  Minion(100 + rand()%20, 20 + rand()%10, 40, tank);
        this->minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        Minion minion = Minion(80 + rand()%20, 30 + rand()%10, 25, melee);
        this->minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        Minion minion = Minion(70 + rand()%20, 40 + rand()%10, 20, ranged);
        this->minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        Minion minion = Minion(65 + rand()%20, 40 + rand()%10, 15, mage);
        this->minions.add(minion);
    }
    for (int counter = 0; counter < 16; counter++) {
        std::cout << "Tank" << counter << ": " << this->minions.get(counter).getDef() << std::endl;
        std::cout << "Melee" << counter << ": " << this->minions.get(counter+16).getDef() << std::endl;
        std::cout << "Ranged" << counter << ": " << this->minions.get(counter+32).getDef() << std::endl;
        std::cout << "Mage" << counter << ": " << this->minions.get(counter+48).getDef() << std::endl;
    }
}

void Waves::newWave() {
    List<Minion> nMinions;
    Minion best;
    Minion minion;
    best = this->getBest(tank);
    for (int counter = 0; counter < 16; counter++) {
        minion =  Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (rand()%10), tank);
        nMinions.add(minion);
    }
    best = this->getBest(melee);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (rand()%10), melee);
        nMinions.add(minion);
    }
    best = this->getBest(ranged);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (rand()%10), ranged);
        nMinions.add(minion);
    }
    best = this->getBest(mage);
    for (int counter = 0; counter < 16; counter++) {
        minion = Minion(best.getHP() + rand()%20, best.getAtk() + rand()%10, best.getDef() + (rand()%10), mage);
        nMinions.add(minion);
    }
    this->minions.delAll();
    for (int counter = 0; counter < 64; counter++) {
        this->minions.add(nMinions.get(counter));
    }
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
Minion* Waves::getMinionPtr(int index) {
    return this->minions.get(index).getPtr();
}
List<Minion> Waves::getMinions() {
    return this->minions;
}