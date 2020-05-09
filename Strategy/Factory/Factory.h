//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_FACTORY_H
#define MYSTRATEGY_FACTORY_H


#include "Spawner.h"

class PhysicalObject;

class Factory : public Spawner {
public:
    Worker * SpawnWorker() override;

    PhysicalSquad * SpawnSwordsman() override;

    PhysicalSquad *SpawnHorseman() override;

    PhysicalSquad *SpawnArcher() override;

    TownHall *SpawnTownHall() override;

    Barracks *SpawnBarracks() override;

    Stable *SpawnStable() override;


    Archery *SpawnArchery() override;

    virtual void DoSomethingWithSpawnedObj(PhysicalObject* obj);
};


#endif //MYSTRATEGY_FACTORY_H
