//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_SQUADSWORDSMAN_H
#define MYSTRATEGY_SQUADSWORDSMAN_H


#include "../Groups/InSquadWarrior.h"

class SquadSwordsman : public InSquadWarrior {
public:
    SquadSwordsman(int _hp = 100, int _defence = 50, int _attack = 30, int _attackRange = 1) {
        //maxMovePoints = 3;
        hp = _hp;
        defence = _defence;
        attack = _attack;
        attackRange = _attackRange;
        type = "Swordsman";
        //appearance = 'S';
    }
};


#endif //MYSTRATEGY_SQUADSWORDSMAN_H
