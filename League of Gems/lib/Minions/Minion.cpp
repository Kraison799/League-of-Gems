//
// Created by ferathor on 07/10/18.
//

#include "Minion.h"
#include <stdlib.h>
#include <iostream>

Minion::Minion() {}
Minion::Minion(int hp, int atk, int def, types type) {
    // Define stats
    this->maxHP = hp;
    this->hp = hp;
    this->atk = atk;
    this->def = def;
    this->type = type;
    // Define in-game stats
    this->dmgDone = 0;
    this->dmgTaken = 0;
    this->fury = false;
}
Minion* Minion::getPtr() {
    return this;
}

int Minion::getDmg(int enemyAtk) {
    // Calculate damage to be taken and update counter
    std::cout << "EnemyAtk: " << enemyAtk << " and def: " << this->getDef() << std::endl;
    int dmg = enemyAtk - enemyAtk*this->getDef()/100;
    std::cout << "Dmg: " << dmg << std::endl;
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
    int hpHeal = this->maxHP*0.15;
    // Set new hp according to hp restored
    if (this->hp + hpHeal >= this->maxHP) {
        this->hp = this->maxHP;
    } else {
        this->hp += hpHeal;
    }
}
void Minion::furySwitch() {
    if (this->fury) {
        this->fury = false;
    } else {
        this->fury = true;
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
int Minion::getDef() {
    return this->def;
}
int Minion::getDmgDone() {
    return this->dmgDone;
}
int Minion::getDmgTaken() {
    return this->dmgTaken;
}