//
// Created by ferathor on 07/10/18.
//

#ifndef LEAGUEOFGEMS_MINION_H
#define LEAGUEOFGEMS_MINION_H

enum types {
    melee,
    ranged,
    tank,
    mage
};

class Minion {
private:
    // Pointer
    Minion *ptr;
    // General Stats
    int maxHP;
    int hp;
    int atk;
    float def;
    types type;
    // In-game Stats
    int dmgDone;
    int dmgTaken;
public:
    // Constructor and pointer
    Minion(int hp, int atk, float def, types type);
    Minion* getPtr();
    // Get damage and heal
    int getDmg(int enemyAtk);
    void heal();
    // Update damage done/taken
    void updateDmgDone(int dmg);
    void updateDmgTaken(int dmg);
    // Getters for Stats
    int getMaxHP();
    int getHP();
    int getAtk();
    float getDef();
    int getDmgDone();
    int getDmgTaken();

    Minion();
};

#endif //LEAGUEOFGEMS_MINION_H
