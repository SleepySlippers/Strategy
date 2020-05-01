//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_UNIT_H
#define STRATEGY_UNIT_H


#include "../Properties/Movable.h"
#include "../Properties/Hittable.h"
#include "../Properties/Named.h"

class Unit : public Movable, public Hittable, public Named {
public:
    ColoredString HandleAction(const string &command) override{
        ColoredString ans;
        ColoredString tmp = Hittable::HandleAction(command);
        if (tmp != NSC){
            ans.Add(tmp);
        }
        tmp = Movable::HandleAction(command);
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

    ColoredString Help() override {
        STANDARD_HELP_FUNCTION_BODY
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Movable::CommandsCanHandle();
        ans += Hittable::CommandsCanHandle();
        ans += Named::CommandsCanHandle();
        return ans;
    }

};


#endif //STRATEGY_UNIT_H
