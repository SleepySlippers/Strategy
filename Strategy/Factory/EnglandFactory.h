//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_ENGLANDFACTORY_H
#define MYSTRATEGY_ENGLANDFACTORY_H


/*#include "Spawner.h"
#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/Swordsman.h"
#include "../AbstractUnits/Horseman.h"
#include "../AbstractUnits/TownHall.h"
#include "../AbstractUnits/Archer.h"
#include "../AbstractUnits/Barracks.h"
#include "../AbstractUnits/PhysicalSquad.h"
#include "../AbstractUnits/SquadSwordsman.h"
#include "../AbstractUnits/SquadHorseman.h"
#include "../AbstractUnits/SquadArcher.h"*/
#include "Factory.h"

class EnglandFactory : public Factory {
public:

    PhysicalSquad * SpawnSwordsman() override;

    PhysicalSquad *SpawnHorseman() override;

    PhysicalSquad *SpawnArcher() override;

    void DoSomethingWithSpawnedObj(PhysicalObject *obj) override;
};


#endif //MYSTRATEGY_ENGLANDFACTORY_H
