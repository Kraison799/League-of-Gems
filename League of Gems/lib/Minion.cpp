//
// Created by ferathor on 07/10/18.
//

#include "Minion.h"

Minion::Minion(int hp, int atk, float def, types type) {
    this->maxHP = hp;
    this->hp = hp;
    this->atk = atk;
    this->def = def;
    this->type = type;
    this->dmgD = 0;
    this->dmgT = 0;
}

int Minion::getMaxHP() {
    return this->maxHP;
}

int Minion::getHP() {
    return  this->hp;
}

int Minion::getAtk() {
    return this->atk;
}

float Minion::getDef() {
    return this->def;
}

int Minion::getDmgT() {
    return this->dmgT;
}

int Minion::getDmgD() {
    return this->dmgD;
}

void Minion::addDmgD(int dmg) {
    this->dmgD += dmg;
}

void Minion::getDmg(Minion enemy) {
    int dmg = enemy.getAtk() - enemy.getAtk()*this->def;
    this->hp -= dmg;
    this->dmgT += dmg;
    enemy.addDmgD(dmg);
}

void Minion::heal(int hp) {
    if (this->hp + hp >= this->maxHP) {
        this->hp = this->maxHP;
    } else {
        this->hp += hp;
    }
}