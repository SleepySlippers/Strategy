//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_ARCHER_H
#define MYSTRATEGY_ARCHER_H


#include "Warrior.h"

class Archer : public Warrior {
public:
    Archer() {
        maxMovePoints = 3;
        hp = 80;
        defence = 20;
        attack = 50;
        attackDistance = 6;
    }
};


#endif //MYSTRATEGY_ARCHER_H
