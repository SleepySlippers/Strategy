//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_ENGLANDFACTORY_H
#define MYSTRATEGY_ENGLANDFACTORY_H


#include "Spawner.h"
#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/Swordman.h"
#include "../AbstractUnits/Horseman.h"
#include "../AbstractUnits/Townhall.h"
#include "../AbstractUnits/Archer.h"
#include "../AbstractUnits/Barracks.h"

class EnglandFactory : public Spawner {
public:
    Worker *SpawnWorker() override {
        Worker* ans = new Worker;
        ans->foncolor = RED;
        return ans;
    }

    Swordman *SpawnSwordman() override {
        Swordman* ans = new Swordman;
        ans->foncolor = RED;
        return ans;
    }

    Horseman *SpawnHorseman() override {
        Horseman* ans = new Horseman;
        ans->foncolor = RED;
        return ans;
    }

    Archer *SpawnArcher() override {
        Archer* ans = new Archer;
        ans->foncolor = RED;
        return ans;
    }

    Townhall *SpawnTownhall() override {
        Townhall* ans = new Townhall;
        ans->foncolor = RED;
        return ans;
    }

    Barracks *SpawnBarracks() override {
        Barracks* ans = new Barracks;
        ans->foncolor = RED;
        return ans;
    }
};


#endif //MYSTRATEGY_ENGLANDFACTORY_H
