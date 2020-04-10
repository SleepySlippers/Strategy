//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_HORSEMAN_H
#define MYSTRATEGY_HORSEMAN_H


#include "Warrior.h"

class Horseman : public Warrior {
public:
    Horseman() {
        maxMovePoints = 6;
        hp = 90;
        defence = 30;
        attack = 35;
        attackDistance = 1;
    }
};


#endif //MYSTRATEGY_HORSEMAN_H
