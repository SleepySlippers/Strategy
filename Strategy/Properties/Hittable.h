//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_HITTABLE_H
#define STRATEGY_HITTABLE_H

#include "Handleable.h"

class ColoredString;

class Hittable : public Handleable {
public:
    int hp = 100;
    int defence = 0;

    virtual void GetDamage(int dmg);

    virtual void OnDeath(){}

    ColoredString HandleAction(const std::string& command) override;

    virtual std::vector<pair<string, string>> CommandsCanHandle() override;
};


#endif //STRATEGY_HITTABLE_H
