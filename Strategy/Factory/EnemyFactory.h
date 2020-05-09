//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_ENEMYFACTORY_H
#define MYSTRATEGY_ENEMYFACTORY_H


#include "TypedFactory.h"
#include "../Properties/Handleable.h"

class EnemyFactory  : public TypedFactory {
public:

    EnemyFactory(int type = ENEMY_HANDLE_TYPE) : TypedFactory(type) {

    }
    /*Spawner *spawner;

    int myType;

    MyFactory(int type) : myType(type)  {

    }

    template<typename T>
    void DoSomethingWithSpawnedObject(T* obj){
        obj->GetMyType() = myType;
    }

    Worker *SpawnWorker() {
        auto tmp = spawner->SpawnWorker();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    PhysicalSquad * SpawnSwordsman() {
        auto tmp = spawner->SpawnSwordsman();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    Stable *SpawnStable(){
        auto tmp = spawner->SpawnStable();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    PhysicalSquad *SpawnHorseman() {
        auto tmp = spawner->SpawnHorseman();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    PhysicalSquad *SpawnArcher() {
        auto tmp = spawner->SpawnArcher();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    TownHall *SpawnTownhall() {
        auto tmp = spawner->SpawnTownHall();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    Barracks *SpawnBarracks() {
        auto tmp = spawner->SpawnBarracks();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }

    Archery *SpawnArchery() {
        auto tmp = spawner->SpawnArchery();
        DoSomethingWithSpawnedObject(tmp);
        return tmp;
    }*/
};

extern EnemyFactory* pEnemyFactory;


#endif //MYSTRATEGY_ENEMYFACTORY_H
