//
// Created by Arseny's on 10.04.2020.
//


class Spawner;
extern Spawner* globalSpawner;

#ifndef MYSTRATEGY_SPAWNER_H
#define MYSTRATEGY_SPAWNER_H


//#include "../AbstractUnits/Swordsman.h"
//#include "../AbstractUnits/Horseman.h"
//#include "../AbstractUnits/Archer.h"
//#include "../AbstractUnits/TownHall.h"
//#include "../AbstractUnits/Worker.h"

class Worker;
class Swordsman;
class Horseman;
class Archer;
class TownHall;
class Barracks;

class Spawner {
public:
    virtual Worker* SpawnWorker() = 0;

    virtual Swordsman* SpawnSwordsman() = 0;

    virtual Horseman* SpawnHorseman() = 0;

    virtual Archer* SpawnArcher() = 0;

    virtual TownHall* SpawnTownhall() = 0;

    virtual Barracks* SpawnBarracks() = 0;
};



#endif //MYSTRATEGY_SPAWNER_H
