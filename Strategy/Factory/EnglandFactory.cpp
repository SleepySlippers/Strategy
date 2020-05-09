//
// Created by Arseny's on 09.05.2020.
//

#include "EnglandFactory.h"

#include "../AbstractUnits/PhysicalSquad.h"
#include "../AbstractUnits/SquadSwordsman.h"
#include "../AbstractUnits/SquadHorseman.h"
#include "../AbstractUnits/SquadArcher.h"

#include "../Groups/Squad.h"

PhysicalSquad *EnglandFactory::SpawnSwordsman() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadSwordsman *tmp = new SquadSwordsman(200, 50, 15, 1);
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

PhysicalSquad *EnglandFactory::SpawnHorseman() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadHorseman *tmp = new SquadHorseman(160, 30, 25, 2);
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

PhysicalSquad *EnglandFactory::SpawnArcher() {
    PhysicalSquad * ans = new PhysicalSquad();
    ans->owner = dynamic_cast<Spawner*>(this);
    SquadArcher *tmp = new SquadArcher(100, 20, 40, 5);
    ans->squad->Add(tmp);
    DoSomethingWithSpawnedObj(ans);
    return ans;
}

void EnglandFactory::DoSomethingWithSpawnedObj(PhysicalObject *obj) {
    obj->fonColor = RED;
}
