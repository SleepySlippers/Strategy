//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_SPAWNER_H
#define MYSTRATEGY_SPAWNER_H

//#include "../AbstractUnits/PhysicalSquad.h"


//#include "../AbstractUnits/Swordsman.h"
//#include "../AbstractUnits/Horseman.h"
//#include "../AbstractUnits/Archer.h"
//#include "../AbstractUnits/TownHall.h"
//#include "../AbstractUnits/Worker.h"

class Worker;
class TownHall;
class Barracks;
class Stable;
class Archery;
class PhysicalSquad;

class Spawner {
public:
    virtual Worker * SpawnWorker() = 0;

    virtual PhysicalSquad * SpawnSwordsman() = 0;

    virtual PhysicalSquad* SpawnHorseman() = 0;

    virtual PhysicalSquad* SpawnArcher() = 0;

    virtual TownHall* SpawnTownHall() = 0;

    virtual Barracks* SpawnBarracks() = 0;

    virtual Stable* SpawnStable() = 0;

    virtual Archery* SpawnArchery() = 0;
};



#endif //MYSTRATEGY_SPAWNER_H
