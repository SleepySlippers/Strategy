//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_SQUADARCHER_H
#define MYSTRATEGY_SQUADARCHER_H

#include "../Groups/InSquadWarrior.h"

class SquadArcher : public InSquadWarrior {
public:
    SquadArcher(int _hp = 50, int _defence = 20, int _attack = 80, int _attackRange = 5) {
        //maxMovePoints = 3;
        hp = _hp;
        defence = _defence;
        attack = _attack;
        attackRange = _attackRange;
        type = "Archer";
        //appearance = 'S';
    }
};


#endif //MYSTRATEGY_SQUADARCHER_H
