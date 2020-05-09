//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_UNIT_H
#define STRATEGY_UNIT_H


#include "../Properties/Movable.h"
#include "../Properties/Hittable.h"
#include "../Properties/Named.h"
#include "../MyUtility.h"

class Unit : public Hittable, public Movable, public Named {
public:
    ColoredString HandleAction(const string &command) override{
        std::istringstream in(command);
        string cmnd;
        in >> cmnd;
        // TODO
        if (cmnd == "Info"){
            ColoredString ans;
            ans.Add(Named::HandleAction("Info"));
            ans.Add(Movable::HandleAction("Info"));
            ans.Add(Hittable::HandleAction("Info"));
            ans.Add("\n");
            return ans;
        }
        ColoredString tmp = Named::HandleAction(command);
        if (tmp != NSC){
            return tmp;
        }
        tmp = Hittable::HandleAction(command);
        if (tmp != NSC){
            return tmp;
        }
        tmp = Movable::HandleAction(command);
        if (tmp != NSC){
            return tmp;
        }
        return NSC;
    }

    ColoredString Help() override {
        STANDARD_HELP_FUNCTION_BODY
    }

    bool CanHandle(int HandlerType) override {
        return Hittable::CanHandle(HandlerType);
    }

    int &GetMyType() override {
        return Hittable::GetMyType();
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Movable::CommandsCanHandle();
        //ans += Hittable::CommandsCanHandle();
        AddVector(ans, Hittable::CommandsCanHandle());
        //ans += Named::CommandsCanHandle();
        AddVector(ans, Named::CommandsCanHandle());
        return ans;
    }

    void OnDeath() override {
        globalMap->Delete(posX, posY);
    }

    virtual ~Unit() = default;
};


#endif //STRATEGY_UNIT_H
