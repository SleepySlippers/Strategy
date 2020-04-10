//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_BUILDING_H
#define MYSTRATEGY_BUILDING_H


#include "../Properties/PhysicalObject.h"
#include "../Properties/Named.h"

class Building : public Named, public PhysicalObject {
public:
    virtual ~Building()= default;
};


#endif //MYSTRATEGY_BUILDING_H
