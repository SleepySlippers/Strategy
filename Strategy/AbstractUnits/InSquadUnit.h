//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_INSQUADUNIT_H
#define MYSTRATEGY_INSQUADUNIT_H


#include "../Properties/Hittable.h"
#include "../Properties/Named.h"
#include "../MyUtilite.h"

class InSquadUnit : public Hittable, public Named {
public:

    ColoredString HandleAction(const string &command) override{
        ColoredString ans;
        ColoredString tmp = Hittable::HandleAction(command);
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
        std::vector<pair<string, string>> ans = Hittable::CommandsCanHandle();
        ans += Named::CommandsCanHandle();
        return ans;
    }
};


#endif //MYSTRATEGY_INSQUADUNIT_H
