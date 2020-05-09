//
// Created by Arseny's on 08.05.2020.
//

#include "TypedFactory.h"

#include "../AbstractUnits/Worker.h"
#include "../AbstractUnits/PhysicalSquad.h"
#include "../AbstractUnits/Stable.h"
#include "../AbstractUnits/TownHall.h"
#include "../AbstractUnits/Barracks.h"
#include "../AbstractUnits/Archery.h"

TypedFactory::TypedFactory(int type) : myType(type)  {

}

Worker *TypedFactory::SpawnWorker() {
    auto tmp = spawner->SpawnWorker();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*Worker* ans = new Worker;
    ans->fonColor = BLUE;
    return ans;*/
}

PhysicalSquad *TypedFactory::SpawnSwordsman() {
    auto tmp = spawner->SpawnSwordsman();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*PhysicalSquad * ans = new PhysicalSquad();
    //Swordsman* ans = new Swordsman;
    SquadSwordsman *tmp = new SquadSwordsman();
    ans->squad->Add(tmp);
    ans->fonColor = BLUE;
    return ans;*/
}

Stable *TypedFactory::SpawnStable() {
    auto tmp = spawner->SpawnStable();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
}

PhysicalSquad *TypedFactory::SpawnHorseman() {
    auto tmp = spawner->SpawnHorseman();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*Horseman* ans = new Horseman;
    ans->fonColor = BLUE;
    return ans;*/
}

PhysicalSquad *TypedFactory::SpawnArcher() {
    auto tmp = spawner->SpawnArcher();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*Archer* ans = new Archer;
    ans->fonColor = BLUE;
    return ans;*/
}

TownHall *TypedFactory::SpawnTownHall() {
    auto tmp = spawner->SpawnTownHall();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*TownHall* ans = new TownHall;
    ans->fonColor = BLUE;
    return ans;*/
}

Barracks *TypedFactory::SpawnBarracks() {
    auto tmp = spawner->SpawnBarracks();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*Barracks* ans = new Barracks;
    ans->fonColor = BLUE;
    return ans;*/
}

Archery *TypedFactory::SpawnArchery() {
    auto tmp = spawner->SpawnArchery();
    DoSomethingWithSpawnedObject(tmp);
    return tmp;
    /*Barracks* ans = new Barracks;
    ans->fonColor = BLUE;
    return ans;*/
}