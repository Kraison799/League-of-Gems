//
// Created by ferathor on 08/11/18.
//

#include "Structure.h"

Structure::Structure() {
    // Set up hp
    this->hp = 130;
}

void Structure::getDmg(int enemyAtk) {
    // Calculate damage to be taken and update counter
    int dmg = enemyAtk - (int)(enemyAtk*0.2;
    // Set new hp according to damage taken
    if (dmg >= this->hp) {
        this->hp = 0;
    } else {
        this->hp -= dmg;
    }
}