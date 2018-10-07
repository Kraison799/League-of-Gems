//
// Created by ferathor on 07/10/18.
//

#ifndef LEAGUEOFGEMS_TARGET_H
#define LEAGUEOFGEMS_TARGET_H

class Target {
private:
    int maxHP;
    int hp;
    float def;
    int posX;
    int posY;
public:
    Target(int maxHp, float def, int posX, int posY);
    void getDmg(int enemyAtk);
};

// MINIONS
class Minion: public Target {
private:
    int atk;
    float atkSpd;
    float moveSpd;
public:
    Minion(int hp, int atk, float def, float atkSpd, float moveSpd, int posX, int posY) : Target(hp, def, posX, posY);
};

class Melee: public Target {
private:
public:
    Melee() : Minion();
    void attack(Target target);
};

class Ranged: public Target {
private:
public:
    Ranged();
    void attack(Target target);
};

class Tank: public Target {
private:
public:
    Tank();
    void attack(Target target);
};

#endif //LEAGUEOFGEMS_TARGET_H
