//
// Created by ferathor on 07/10/18.
//

#ifndef LEAGUEOFGEMS_MINION_H
#define LEAGUEOFGEMS_MINION_H

enum types {
    melee;
    ranged;
    mage;
    tank;
};

class Minion {
private:
    int maxHP;
    int hp;
    int atk;
    float def;
    int dmgD;      // Damage taken by enemy attacks
    int dmgT;      // Damage done to enemies
    types type;
public:
    Minion(int hp, int atk, float def, types type);
    void getDmg(Minion enemy);
    int getHP();
    int getMaxHP();
    int getAtk();
    float getDef();
    int getDmgT();
    int getDmgD();
    void addDmgD(int dmg);
    void heal(int hp);
};

#endif //LEAGUEOFGEMS_MINION_H
