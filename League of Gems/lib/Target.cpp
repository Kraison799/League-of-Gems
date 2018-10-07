//
// Created by ferathor on 07/10/18.
//

#include "Target.h"

Target::Target(int hp, float def, int posX, int posY) {
    this->maxHP = hp;
    this->hp = hp;
    this->def = def;
    this->posX = posX;
    this->posY = posY;
}

void Target::getDmg(int enemyAtk) {
    int dmg = enemyAtk - enemyAtk*this->def;
    if (this->hp > dmg) {
        this->hp -= dmg;
    } else {
        this->hp = 0;
    }
}

// MINIONS
Minion::Minion(int hp, int atk, float def, float atkSpd, float moveSpd, int posX, int posY) {

}