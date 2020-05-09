//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_PHYSICALSQUAD_H
#define MYSTRATEGY_PHYSICALSQUAD_H

//class Movable;
//class Named;
class Squad;

#include "../Properties/Movable.h"
#include "../Properties/Named.h"

class PhysicalSquad : public Movable, public Named {
public:
    Squad *squad;

    PhysicalSquad();

    void AttackSquad(Squad* enemy);

    bool CanHandle(int HandlerType) override;

    int &GetMyType() override;

    ColoredString HandleAction(const string &command) override;

    ColoredString Help() override;

    std::vector<pair<string, string>> CommandsCanHandle() override;

    void DeathCheck();

    void DestroySelf();

    ~PhysicalSquad() override;
};




#endif //MYSTRATEGY_PHYSICALSQUAD_H
