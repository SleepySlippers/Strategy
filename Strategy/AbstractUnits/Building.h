//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_BUILDING_H
#define MYSTRATEGY_BUILDING_H

#include "../Properties/PhysicalObject.h"
#include "../Properties/Named.h"
#include "../Properties/Hittable.h"

class Building : public Named, public PhysicalObject, public Hittable {
public:

    ColoredString HandleAction(const string &command) override;

    bool CanHandle(int HandlerType) override;

    int &GetMyType() override;

    std::vector<pair<string, string>> CommandsCanHandle() override;

    virtual ~Building()= default;
};


#endif //MYSTRATEGY_BUILDING_H
