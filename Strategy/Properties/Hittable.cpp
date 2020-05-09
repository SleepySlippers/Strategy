//
// Created by Arseny's on 08.05.2020.
//

#include <sstream>
#include "Hittable.h"

void Hittable::GetDamage(int dmg) {
    if (hp <= 0) return;
    hp -= dmg * (100 - defence) / 100;
    if (hp <= 0){
        OnDeath();
    }
}

ColoredString Hittable::HandleAction(const string &command) {
    std::istringstream in(command);
    std::string cmnd;
    in >> cmnd;
    if (cmnd == "Info"){
        ColoredString ans;
        ans.Add("HP: ");
        ans.Add(hp, YELLOW);
        ans.Add(" DEF: ");
        ans.Add(defence, YELLOW);
        ans.Add("% ");
        return ans;
    }
    if (cmnd == "Help" || cmnd == "help"){
        return Help();
    }
    return NSC;
}

std::vector<pair<string, string>> Hittable::CommandsCanHandle() {
    std::vector<pair<string, string>> ans;
    if (NEED_INFO) {
        ans.push_back({"Info", "- full information"});
    }
    return ans;
}
