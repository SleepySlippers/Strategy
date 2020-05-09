//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_FRANCEFACTORY_H
#define MYSTRATEGY_FRANCEFACTORY_H

#include "Factory.h"

class FranceFactory : public Factory {
public:

    void DoSomethingWithSpawnedObj(PhysicalObject *obj) override {
        obj->fonColor = BLUE;
    }
};


#endif //MYSTRATEGY_FRANCEFACTORY_H
