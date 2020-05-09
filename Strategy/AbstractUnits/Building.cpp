//
// Created by Arseny's on 09.05.2020.
//

#include "Building.h"

#include "../MyUtility.h"

ColoredString Building::HandleAction(const string &command) {
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

bool Building::CanHandle(int HandlerType) {
    return Hittable::CanHandle(HandlerType);
}

int &Building::GetMyType() {
    return Hittable::GetMyType();
}

std::vector<pair<string, string>> Building::CommandsCanHandle() {
    std::vector<pair<string, string>> ans = Hittable::CommandsCanHandle();
    ans += PhysicalObject::CommandsCanHandle();
    ans += Named::CommandsCanHandle();
    return ans;
}
