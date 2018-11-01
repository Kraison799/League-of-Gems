//
// Created by ferathor on 07/10/18.
//

#include "../ADT/List.h"
#include "../Minions/Minion.h"
#include "../ADT/List.h"

#ifndef LEAGUEOFGEMS_WAVES_H
#define LEAGUEOFGEMS_WAVES_H

class Waves {
private:
    List<Minion> minions;
public:
    // Constructor
    Waves();
    // Getter
    Minion getMinion(int index);
    List<Minion> getMinions();
};

#endif //LEAGUEOFGEMS_WAVES_H
