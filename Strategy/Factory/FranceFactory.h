//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_FRANCEFACTORY_H
#define MYSTRATEGY_FRANCEFACTORY_H


#include "Spawner.h"
#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/Swordsman.h"
#include "../AbstractUnits/Horseman.h"
#include "../AbstractUnits/TownHall.h"
#include "../AbstractUnits/Archer.h"
#include "../AbstractUnits/PhysicalSquad.h"
#include "../AbstractUnits/SquadSwordsman.h"

class FranceFactory : public Spawner {
public:
    Worker *SpawnWorker() override {
        Worker* ans = new Worker;
        ans->fonColor = BLUE;
        return ans;
    }

    /*Swordsman *SpawnSwordsman() override {
        Swordsman* ans = new Swordsman;
        ans->fonColor = BLUE;
        return ans;
    }*/

    PhysicalSquad * SpawnSwordsman() override {
        PhysicalSquad * ans = new PhysicalSquad();
        //Swordsman* ans = new Swordsman;
        SquadSwordsman *tmp = new SquadSwordsman();
        ans->squad->Add(tmp);
        ans->fonColor = BLUE;
        return ans;
    }

    Horseman *SpawnHorseman() override {
        Horseman* ans = new Horseman;
        ans->fonColor = BLUE;
        return ans;
    }

    Archer *SpawnArcher() override {
        Archer* ans = new Archer;
        ans->fonColor = BLUE;
        return ans;
    }

    TownHall *SpawnTownhall() override {
        TownHall* ans = new TownHall;
        ans->fonColor = BLUE;
        return ans;
    }

    Barracks *SpawnBarracks() override {
        Barracks* ans = new Barracks;
        ans->fonColor = BLUE;
        return ans;
    }
};


#endif //MYSTRATEGY_FRANCEFACTORY_H
