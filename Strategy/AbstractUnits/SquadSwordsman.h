//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_SQUADSWORDSMAN_H
#define MYSTRATEGY_SQUADSWORDSMAN_H


#include "../Groups/InSquadWarrior.h"

class SquadSwordsman : public InSquadWarrior {
public:
    SquadSwordsman() {
        //maxMovePoints = 3;
        hp = 100;
        defence = 40;
        attack = 80;
        attackRange = 1;
        //appearance = 'S';
    }
};


#endif //MYSTRATEGY_SQUADSWORDSMAN_H
