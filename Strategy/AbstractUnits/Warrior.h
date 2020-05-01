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
    int attackRange = 1;

    virtual bool CanHit(const Hittable &other){
        return abs(posX - dynamic_cast<const PhysicalObject &>(other).posX) +
               abs(posY - dynamic_cast<const PhysicalObject &>(other).posY) <= attackRange;
    }

    virtual bool Hit(Hittable &other){
        if (!CanHit(other))
            return false;
        other.GetDamage(attack);
        return true;
    }

    ColoredString HandleAction(const std::string& command) override{
        std::istringstream in(command);
        string cmnd;
        in >> cmnd;
        // TODO
        if (cmnd == "Info"){
            ColoredString ans;
            ans.Add("Attack strength: ");
            ans.Add(attack, YELLOW);
            ans.Add("\nAttack range: ");
            ans.Add(attackRange, YELLOW);
            ans.Add("\n");
            ans.Add(Unit::HandleAction("Info"));
            return ans;
        }
        return Unit::HandleAction(command);
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Unit::CommandsCanHandle();
        // TODO
        if (NEED_INFO) {
            ans.push_back({"Info", "- full information"});
        }
        return ans;
    }
};


#endif //STRATEGY_WARRIOR_H
