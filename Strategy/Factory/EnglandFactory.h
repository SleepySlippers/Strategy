//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_ENGLANDFACTORY_H
#define MYSTRATEGY_ENGLANDFACTORY_H


#include "Spawner.h"
#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/Swordsman.h"
#include "../AbstractUnits/Horseman.h"
#include "../AbstractUnits/TownHall.h"
#include "../AbstractUnits/Archer.h"
#include "../AbstractUnits/Barracks.h"
#include "../AbstractUnits/PhysicalSquad.h"
#include "../AbstractUnits/SquadSwordsman.h"

class EnglandFactory : public Spawner {
public:
    Worker *SpawnWorker() override {
        Worker* ans = new Worker;
        ans->fonColor = RED;
        return ans;
    }

    /*Swordsman *SpawnSwordsman() override {
        Swordsman* ans = new Swordsman;
        ans->fonColor = RED;
        return ans;
    }*/

    PhysicalSquad * SpawnSwordsman() override {
        PhysicalSquad * ans = new PhysicalSquad();
        //Swordsman* ans = new Swordsman;
        SquadSwordsman *tmp = new SquadSwordsman();
        ans->squad->Add(tmp);
        ans->fonColor = RED;
        return ans;
    }

    Horseman *SpawnHorseman() override {
        Horseman* ans = new Horseman;
        ans->fonColor = RED;
        return ans;
    }

    Archer *SpawnArcher() override {
        Archer* ans = new Archer;
        ans->fonColor = RED;
        return ans;
    }

    TownHall *SpawnTownhall() override {
        TownHall* ans = new TownHall;
        ans->fonColor = RED;
        return ans;
    }

    Barracks *SpawnBarracks() override {
        Barracks* ans = new Barracks;
        ans->fonColor = RED;
        return ans;
    }
};


#endif //MYSTRATEGY_ENGLANDFACTORY_H
