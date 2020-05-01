//
// Created by Arseny's on 10.04.2020.
//


#include "../AbstractUnits/PhysicalSquad.h"

class Spawner;
//extern Spawner* mySpawner;
//extern Spawner* enemySpawner;

#ifndef MYSTRATEGY_SPAWNER_H
#define MYSTRATEGY_SPAWNER_H


//#include "../AbstractUnits/Swordsman.h"
//#include "../AbstractUnits/Horseman.h"
//#include "../AbstractUnits/Archer.h"
//#include "../AbstractUnits/TownHall.h"
//#include "../AbstractUnits/Worker.h"

class Worker;
class Horseman;
class Archer;
class TownHall;
class Barracks;

class Spawner {
public:
    virtual Worker* SpawnWorker() = 0;

    virtual PhysicalSquad * SpawnSwordsman() = 0;

    virtual Horseman* SpawnHorseman() = 0;

    virtual Archer* SpawnArcher() = 0;

    virtual TownHall* SpawnTownhall() = 0;

    virtual Barracks* SpawnBarracks() = 0;
};



#endif //MYSTRATEGY_SPAWNER_H
