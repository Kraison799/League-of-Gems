//
// Created by ferathor on 07/10/18.
//

#include "Waves.h"
#include "Minion.h"
#include "Minion.cpp"
#include <stdlib.h>

Waves::Waves() {
    this->minions = Minion[64];
    int counter = 0;
    while (counter < 16) {
        Minion newMinion = Minion::Minion(75 + rand()%30, 20 + rand()%10, 0.15 + (float)(rand()%10)/100, melee);
        counter++;
    }
    while (counter < 32) {
        Minion newMinion = Minion::Minion(105 + rand()%30, 15 + rand()%10, 0.30 + (float)(rand()%10)/100, tank);
        counter++;
    }
    while (counter < 48) {
        Minion newMinion = Minion::Minion(60 + rand()%30, 25 + rand()%10, 0.15 + (float)(rand()%10)/100, ranged);
        counter++;
    }
    while (counter < 64) {
        Minion newMinion = Minion::Minion(55 + rand()%30, 35 + rand()%10, 0.15 + (float)(rand()%10)/100, mage);
        counter++;
    }
}

void Waves::getNewWave() {
    Minion best = minions[0];
    for (int count = 0; count < 16; count++) {
        if (this->minions[count].getDmgD > best.getDmgD() && minions[count].getDmgT < best.getDmgT()) {
            best = this->minions[count];
        }
    }
    for (int count = 0; count < 16; count++) {
        this->minions[count] = Minion::Minion(best.getMaxHP() + rand()%30, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, melee);
    }
    best = minions[16];
    for (int count = 16; count < 32; count++) {
        if (this->minions[count].getDmgD > best.getDmgD() && minions[count].getDmgT < best.getDmgT()) {
            best = this->minions[count];
        }
    }
    for (int count = 16; count < 32; count++) {
        this->minions[count] = Minion::Minion(best.getMaxHP() + rand()%30, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, tank);
    }
    best = minions[32];
    for (int count = 32; count < 48; count++) {
        if (this->minions[count].getDmgD > best.getDmgD() && minions[count].getDmgT < best.getDmgT()) {
            best = this->minions[count];
        }
    }
    for (int count = 32; count < 48; count++) {
        this->minions[count] = Minion::Minion(best.getMaxHP() + rand()%30, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, ranged);
    }
    best = minions[48];
    for (int count = 48; count < 64; count++) {
        if (this->minions[count].getDmgD > best.getDmgD() && minions[count].getDmgT < best.getDmgT()) {
            best = this->minions[count];
        }
    }
    for (int count = 48; count < 64; count++) {
        this->minions[count] = Minion::Minion(best.getMaxHP() + rand()%30, best.getAtk() + rand()%10, best.getDef() + (float)(rand()%10)/100, mage);
    }
}