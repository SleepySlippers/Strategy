//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_FRANCEFACTORY_H
#define MYSTRATEGY_FRANCEFACTORY_H


#include "Spawner.h"
#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/Swordman.h"
#include "../AbstractUnits/Horseman.h"
#include "../AbstractUnits/Townhall.h"
#include "../AbstractUnits/Archer.h"

class FranceFactory : public Spawner {
public:
    Worker *SpawnWorker() override {
        Worker* ans = new Worker;
        ans->foncolor = BLUE;
        return ans;
    }

    Swordman *SpawnSwordman() override {
        Swordman* ans = new Swordman;
        ans->foncolor = BLUE;
        return ans;
    }

    Horseman *SpawnHorseman() override {
        Horseman* ans = new Horseman;
        ans->foncolor = BLUE;
        return ans;
    }

    Archer *SpawnArcher() override {
        Archer* ans = new Archer;
        ans->foncolor = BLUE;
        return ans;
    }

    Townhall *SpawnTownhall() override {
        Townhall* ans = new Townhall;
        ans->foncolor = BLUE;
        return ans;
    }

    Barracks *SpawnBarracks() override {
        Barracks* ans = new Barracks;
        ans->foncolor = BLUE;
        return ans;
    }
};


#endif //MYSTRATEGY_FRANCEFACTORY_H
