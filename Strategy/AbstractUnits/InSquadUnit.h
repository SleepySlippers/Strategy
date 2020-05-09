//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_INSQUADUNIT_H
#define MYSTRATEGY_INSQUADUNIT_H


#include "../Properties/Hittable.h"
#include "../Properties/Named.h"
#include "../MyUtility.h"

class InSquadUnit : public Hittable, public Named {
public:

    ColoredString HandleAction(const string &command) override{
        std::istringstream in(command);
        string cmnd;
        in >> cmnd;
        // TODO
        if (cmnd == "Info"){
            ColoredString ans;
            ans.Add(Named::HandleAction("Info"));
            ans.Add(Hittable::HandleAction("Info"));
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
        return NSC;
    }

    ColoredString Help() override {
        STANDARD_HELP_FUNCTION_BODY
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Hittable::CommandsCanHandle();
        ans += Named::CommandsCanHandle();
        return ans;
    }
};


#endif //MYSTRATEGY_INSQUADUNIT_H
