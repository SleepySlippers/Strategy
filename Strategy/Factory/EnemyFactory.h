//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_ENEMYFACTORY_H
#define MYSTRATEGY_ENEMYFACTORY_H


#include "Spawner.h"

class EnemyFactory {
public:
    Spawner *spwnr;

    int myType;

    EnemyFactory(int type) : myType(type) {

    }

    template<typename T>
    void DoSomethingWithSpawnedObject(T* obj){
        obj->GetMyType() = myType;
    }

    Worker *SpawnWorker() {
        auto tmp = spwnr->SpawnWorker();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*Worker* ans = new Worker;
        ans->fonColor = BLUE;
        return ans;*/
    }

    /*Swordsman *SpawnSwordsman() override {
        Swordsman* ans = new Swordsman;
        ans->fonColor = BLUE;
        return ans;
    }*/

    PhysicalSquad * SpawnSwordsman() {
        auto tmp = spwnr->SpawnSwordsman();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*PhysicalSquad * ans = new PhysicalSquad();
        //Swordsman* ans = new Swordsman;
        SquadSwordsman *tmp = new SquadSwordsman();
        ans->squad->Add(tmp);
        ans->fonColor = BLUE;
        return ans;*/
    }

    Horseman *SpawnHorseman() {
        auto tmp = spwnr->SpawnHorseman();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*Horseman* ans = new Horseman;
        ans->fonColor = BLUE;
        return ans;*/
    }

    Archer *SpawnArcher() {
        auto tmp = spwnr->SpawnArcher();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*Archer* ans = new Archer;
        ans->fonColor = BLUE;
        return ans;*/
    }

    TownHall *SpawnTownhall() {
        auto tmp = spwnr->SpawnTownhall();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*TownHall* ans = new TownHall;
        ans->fonColor = BLUE;
        return ans;*/
    }

    Barracks *SpawnBarracks() {
        auto tmp = spwnr->SpawnBarracks();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
        /*Barracks* ans = new Barracks;
        ans->fonColor = BLUE;
        return ans;*/
    }
};

extern EnemyFactory* enemySpawner;


#endif //MYSTRATEGY_ENEMYFACTORY_H
