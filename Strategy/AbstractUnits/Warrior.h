//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_WARRIOR_H
#define STRATEGY_WARRIOR_H

#include <cstdlib>
#include "Unit.h"

class Warrior : public Unit {
public:
    int attack = 10;
    int attackDistance = 1;

    virtual bool CanHit(const Hittable &other){
        return abs(posX - dynamic_cast<const PhysicalObject &>(other).posX) +
               abs(posY - dynamic_cast<const PhysicalObject &>(other).posY) <= attackDistance;
    }

    virtual bool Hit(Hittable &other){
        if (!CanHit(other))
            return false;
        other.GetDamage(attack);
        return true;
    }

    std::string HandleAction(const std::string& command) override{
        std::istringstream in(command);
        string cmnd;
        in >> cmnd;
        //if (cmnd == )
        return Unit::HandleAction(command);
    }
};


#endif //STRATEGY_WARRIOR_H
