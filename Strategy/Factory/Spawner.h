//
// Created by Arseny's on 10.04.2020.
//


class Spawner;
extern Spawner* globalSpawner;

#ifndef MYSTRATEGY_SPAWNER_H
#define MYSTRATEGY_SPAWNER_H


//#include "../AbstractUnits/Swordman.h"
//#include "../AbstractUnits/Horseman.h"
//#include "../AbstractUnits/Archer.h"
//#include "../AbstractUnits/Townhall.h"
//#include "../AbstractUnits/Worker.h"

class Worker;
class Swordman;
class Horseman;
class Archer;
class Townhall;
class Barracks;

class Spawner {
public:
    virtual Worker* SpawnWorker() = 0;

    virtual Swordman* SpawnSwordman() = 0;

    virtual Horseman* SpawnHorseman() = 0;

    virtual Archer* SpawnArcher() = 0;

    virtual Townhall* SpawnTownhall() = 0;

    virtual Barracks* SpawnBarracks() = 0;
};



#endif //MYSTRATEGY_SPAWNER_H
