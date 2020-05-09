//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_SQUADHORSEMAN_H
#define MYSTRATEGY_SQUADHORSEMAN_H


#include "../Groups/InSquadWarrior.h"

class SquadHorseman : public InSquadWarrior {
public:
    SquadHorseman(int _hp = 80, int _defence = 30, int _attack = 50, int _attackRange = 2) {
        hp = _hp;
        defence = _defence;
        attack = _attack;
        attackRange = _attackRange;
        type = "Horseman";
    }
};


#endif //MYSTRATEGY_SQUADHORSEMAN_H
