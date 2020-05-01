//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_SWORDSMEN_H
#define STRATEGY_SWORDSMEN_H


#include "Warrior.h"

class Swordsman : public Warrior {
public:
    Swordsman() {
        maxMovePoints = 3;
        hp = 100;
        defence = 40;
        attack = 30;
        attackRange = 1;
        appearance = 'S';
    }
};


#endif //STRATEGY_SWORDSMEN_H
