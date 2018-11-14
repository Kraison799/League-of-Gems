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
    int def;
    types type;
    // In-game Stats
    int dmgDone;
    int dmgTaken;
    bool fury;
public:
    // Constructor and pointer
    Minion(int hp, int atk, int def, types type);
    Minion* getPtr();
    // Get damage, fury and heal
    int getDmg(int enemyAtk);
    void heal();
    void furySwitch();
    // Update damage done/taken
    void updateDmgDone(int dmg);
    void updateDmgTaken(int dmg);
    // Getters for Stats
    int getMaxHP();
    int getHP();
    int getAtk();
    int getDef();
    int getDmgDone();
    int getDmgTaken();

    Minion();
};

#endif //LEAGUEOFGEMS_MINION_H
