//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_TYPEDFACTORY_H
#define MYSTRATEGY_TYPEDFACTORY_H

#include "Spawner.h"





class TypedFactory {
public:
    Spawner *spawner;

    int myType;

    explicit TypedFactory(int type);

    template<typename T>
    void DoSomethingWithSpawnedObject(T* obj);

    Worker *SpawnWorker();

    PhysicalSquad * SpawnSwordsman();

    Stable *SpawnStable();

    PhysicalSquad *SpawnHorseman();

    PhysicalSquad *SpawnArcher();

    TownHall *SpawnTownHall();

    Barracks *SpawnBarracks();

    Archery *SpawnArchery();
};

template<typename T>
void TypedFactory::DoSomethingWithSpawnedObject(T *obj) {
    obj->GetMyType() = myType;
}

#endif //MYSTRATEGY_TYPEDFACTORY_H
