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
    string HandleAction(const string &command) override{
        std::ostringstream ans;
        string tmp = Movable::HandleAction(command);
        if (tmp != NSC){
            ans << tmp;
        }
        tmp = Hittable::HandleAction(command);
        if (tmp != NSC){
            ans << tmp;
        }
        if (ans.str().empty()){
            return NSC;
        }
        return ans.str();
    }

    string CommandsCanHandle() override{
        std::ostringstream ans;
        ans << Hittable::CommandsCanHandle();
        ans << Movable::CommandsCanHandle();
        return ans.str();
    }

};


#endif //STRATEGY_UNIT_H
