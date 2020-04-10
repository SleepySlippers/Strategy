//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_SWORDMEN_H
#define STRATEGY_SWORDMEN_H


#include "Warrior.h"

class Swordman : public Warrior {
public:
    Swordman() {
        maxMovePoints = 3;
        hp = 100;
        defence = 40;
        attack = 30;
        attackDistance = 1;
        appearance = 'S';
    }
};


#endif //STRATEGY_SWORDMEN_H
