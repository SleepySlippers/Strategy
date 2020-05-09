//
// Created by Arseny's on 09.05.2020.
//

#include "MapInit.h"

#include "Factory/MyFactory.h"
#include "Factory/EnemyFactory.h"

#include "AbstractUnits/PhysicalSquad.h"
#include "AbstractUnits/TownHall.h"
#include "AbstractUnits/Archery.h"
#include "AbstractUnits/Barracks.h"
#include "AbstractUnits/Stable.h"

#include "MainHandler.h"

void MapInit() {
    globalMap = new Map;
    TownHall *Th = pMyFactory->SpawnTownHall();
    Th->TeleportTo(5, 10);
    globalMap->Place(Th);
    Th->ChangeName("TownHall");
    mainHandler->HandleAction("Choose TownHall");

    Th = pEnemyFactory->SpawnTownHall();
    Th->TeleportTo(15, 10);
    globalMap->Place(Th);
    Th->ChangeName("EnemyTownHall");
    {
        auto tmp = pEnemyFactory->SpawnSwordsman();
        tmp->TeleportTo(10, 10);
        globalMap->Place(tmp);
        //tmp->ChangeName("EnemySwordsman");
    }
    {
        auto tmp = pEnemyFactory->SpawnSwordsman();
        tmp->TeleportTo(11, 10);
        globalMap->Place(tmp);
        //tmp->ChangeName("EnemySwordsman");
    }
    {
        auto tmp = pMyFactory->SpawnSwordsman();
        tmp->TeleportTo(9, 10);
        globalMap->Place(tmp);
        tmp->ChangeName(tryName("Squad"));
        mainHandler->HandleAction("Choose " + tmp->GetName());
    }
    {
        auto tmp = pMyFactory->SpawnArchery();
        tmp->TeleportTo(7, 12);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnArcher");
        tmp->ChangeName(tryName("Archery"));
    }
#ifdef _DEB
    {
        auto tmp = pEnemyFactory->SpawnWorker();
        tmp->TeleportTo(8, 11);
        globalMap->Place(tmp);
    }
#endif
    {
        auto tmp = pMyFactory->SpawnBarracks();
        tmp->TeleportTo(7, 13);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnSwordsman");
#ifdef _DEB
        mainHandler->HandleAction("EndTurn");
        names["Squad5"]->HandleAction("Move Up");
        names["Squad5"]->HandleAction("Attack Up");
#endif
        tmp->ChangeName(tryName("Barracks"));
    }
    {
        auto tmp = pMyFactory->SpawnStable();
        tmp->TeleportTo(7, 14);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnHorseman");
        tmp->ChangeName(tryName("Stable"));
    }
    {
        auto tmp = pEnemyFactory->SpawnArchery();
        tmp->TeleportTo(12, 12);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnArcher");
        tmp->ChangeName(tryName("EnemyArchery"));
    }
    {
        auto tmp = pEnemyFactory->SpawnBarracks();
        tmp->TeleportTo(12, 13);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnSwordsman");
        tmp->ChangeName(tryName("EnemyBarracks"));
    }
    {
        auto tmp = pEnemyFactory->SpawnStable();
        tmp->TeleportTo(12, 14);
        globalMap->Place(tmp);
        tmp->HandleAction("SpawnHorseman");
        tmp->ChangeName(tryName("EnemyStable"));
    }
    mainHandler->HandleAction("EndTurn");
/*#ifdef _DEB
    PhysicalSquad *tmp = pMyFactory->SpawnSwordsman();
    tmp->TeleportTo(5, 5);
    globalMap->Place(tmp);
    tmp->ChangeName("Sword1");
    tmp = pMyFactory->SpawnSwordsman();
    tmp->TeleportTo(5, 6);
    globalMap->Place(tmp);
    tmp->ChangeName("Sword2");
    mainHandler->HandleAction("EndTurn");
    mainHandler->HandleAction("Choose Sword1");
    mainHandler->HandleAction("Move Down");
    mainHandler->HandleAction("EndTurn");
#endif*/
}
