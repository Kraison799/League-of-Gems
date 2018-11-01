//
// Created by ferathor on 07/10/18.
//

#include "Minion.h"
#include <stdlib.h>
#include <iostream>

Minion::Minion() {}
Minion::Minion(int hp, int atk, float def, types type) {
    // Define stats
    this->maxHP = hp;
    this->hp = hp;
    this->def = def;
    this->type = type;
    // Define in-game stats
    this->dmgDone = 0;
    this->dmgTaken = 0;
    // Define pointer
    this->ptr = static_cast<Minion *>(malloc(sizeof(this)));
}
Minion* Minion::getPtr() {
    return this->ptr;
}

int Minion::getDmg(int enemyAtk) {
    // Calculate damage to be taken and update counter
    int dmg = enemyAtk - (int)(enemyAtk*this->def);
    this->updateDmgTaken(dmg);
    // Set new hp according to damage taken
    if (dmg >= this->hp) {
        this->hp = 0;
    } else {
        this->hp -= dmg;
    }
    // Return damage taken
    return dmg;
}
void Minion::heal() {
    // Calculate hp to be restore
    int hpHeal = this->maxHP*0.10;
    // Set new hp according to hp restored
    if (this->hp + hpHeal >= this->maxHP) {
        this->hp = this->maxHP;
    } else {
        this->hp += hpHeal;
    }
}

void Minion::updateDmgDone(int dmg) {
    this->dmgDone += dmg;
}
void Minion::updateDmgTaken(int dmg) {
    this->dmgTaken += dmg;
}

int Minion::getMaxHP() {
    return this->maxHP;
}
int Minion::getHP() {
    return this->hp;
}
int Minion::getAtk() {
    return this->atk;
}
float Minion::getDef() {
    return this->def;
}
int Minion::getDmgDone() {
    return this->dmgDone;
}
int Minion::getDmgTaken() {
    return this->dmgTaken;
}