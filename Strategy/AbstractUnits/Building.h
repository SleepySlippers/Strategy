//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_BUILDING_H
#define MYSTRATEGY_BUILDING_H


#include "../Properties/PhysicalObject.h"
#include "../Properties/Named.h"

class Building : public Named, public PhysicalObject, public Hittable {
public:

    ColoredString HandleAction(const string &command) override{
        ColoredString ans;
        ColoredString tmp = Hittable::HandleAction(command);
        if (tmp != NSC){
            ans.Add(tmp);
        }
        tmp = PhysicalObject::HandleAction(command);
        if (tmp != NSC){
            ans.Add(tmp);
        }
        tmp = Named::HandleAction(command);
        if (tmp != NSC){
            ans.Add(tmp);
        }
        if (!ans.size()){
            return NSC;
        }
        return ans;
    }

    bool CanHandle(int HandlerType) override {
        return Hittable::CanHandle(HandlerType);
    }

    int &GetMyType() override {
        return Hittable::GetMyType();
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Hittable::CommandsCanHandle();
        ans += PhysicalObject::CommandsCanHandle();
        ans += Named::CommandsCanHandle();
        return ans;
    }

    virtual ~Building()= default;
};


#endif //MYSTRATEGY_BUILDING_H
