//
// Created by Arseny's on 09.05.2020.
//

#include "Factory.h"


#include "../AbstractUnits/Worker.h"

#include "../AbstractUnits/SquadSwordsman.h"
#include "../AbstractUnits/SquadHorseman.h"
#include "../AbstractUnits/SquadArcher.h"
#include "../AbstractUnits/PhysicalSquad.h"

#include "../AbstractUnits/TownHall.h"
#include "../AbstractUnits/Barracks.h"
#include "../AbstractUnits/Archery.h"
#include "../AbstractUnits/Stable.h"

#include "../Groups/Squad.h"

Worker *Factory::SpawnWorker() {
    Worker* ans = new Worker;
    //ans->spawner = dynamic_cast<Spawner*>(this);
    ans->owner = dynamic_cast<Spawner*>(this);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

PhysicalSquad *Factory::SpawnSwordsman() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadSwordsman *tmp = new SquadSwordsman();
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

PhysicalSquad *Factory::SpawnHorseman() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadHorseman *tmp = new SquadHorseman();
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

PhysicalSquad *Factory::SpawnArcher() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadArcher *tmp = new SquadArcher();
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

TownHall *Factory::SpawnTownHall() {
    TownHall* ans = new TownHall;
    ans->owner = dynamic_cast<Spawner*>(this);
    //ans->spawner = dynamic_cast<Spawner*>(this);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

Barracks *Factory::SpawnBarracks() {
    Barracks* ans = new Barracks;
    ans->owner = dynamic_cast<Spawner*>(this);
    //ans->spawner = dynamic_cast<Spawner*>(this);
    //ans->owner = dynamic_cast<Spawner*>(this);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

Stable *Factory::SpawnStable() {
    Stable* ans = new Stable;
    ans->owner = dynamic_cast<Spawner*>(this);
    //ans->spawner = dynamic_cast<Spawner*>(this);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

Archery *Factory::SpawnArchery() {
    Archery* ans = new Archery;
    ans->owner = dynamic_cast<Spawner*>(this);
    //ans->spawner = dynamic_cast<Spawner*>(this);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

void Factory::DoSomethingWithSpawnedObj(PhysicalObject *obj) {}
