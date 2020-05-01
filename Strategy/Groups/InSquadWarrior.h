//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_INSQUADWARRIOR_H
#define MYSTRATEGY_INSQUADWARRIOR_H

#include <sstream>
#include "../AbstractUnits/InSquadUnit.h"
#include "Group.h"

class InSquadWarrior : public InSquadUnit, public Group {
public:
    int attack = 60;
    int attackRange = 1;
    string type = "Swordsman";

    ColoredString HandleAction(const string &command) override{
        std::istringstream in(command);
        string cmnd;
        in >> cmnd;
        if (cmnd == "Info"){
            ColoredString ans;
            ans.Add("Attack strength: ");
            ans.Add(attack, YELLOW);
            ans.Add("\nAttack range: ");
            ans.Add(attackRange, YELLOW);
            ans.Add("\n");
            ans.Add(InSquadUnit::HandleAction("Info"));
            return ans;
        }
        return InSquadUnit::HandleAction(command);
    }

    std::vector<pair<std::string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = InSquadUnit::CommandsCanHandle();
        if (NEED_INFO) {
            ans.emplace_back("Info", "- full information");
        }
        return ans;
    }

    map<string, int> ReCount() override {
        return map<string, int>{{type, 1}};
    }

    vector<InSquadWarrior*> GetAllMembers() override {
        return std::vector<InSquadWarrior*>(1, this);
    }

    void OnDeath() override {
        if (_parent != nullptr){
            _parent->Remove(this);
        }
        delete this;
    }

    ColoredString GetInfo() override {
        return HandleAction("Info");
    }
};


#endif //MYSTRATEGY_INSQUADWARRIOR_H
