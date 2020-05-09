//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_SQUAD_H
#define MYSTRATEGY_SQUAD_H


#include "../MyUtility.h"
#include "Group.h"
#include <list>
#include "InSquadWarrior.h"

class Squad : public Group {
protected:
    std::list<Group*> _children;
public:
    void Add(Group *group) override {
        _children.push_back(group);
        group->SetParent(this);
    }

    void Remove(Group *group) override {
        _children.remove(group);
        group->SetParent(nullptr);
    }

    bool IsComposite() const override {
        return true;
    }

    map<string, int> ReCount() override {
        map<string, int> ans;
        for (auto it: _children){
            //ans.merge(it->ReCount());
            //ans += it->ReCount();
            AddMap(ans, it->ReCount());
        }
        return ans;
    }

    vector<InSquadWarrior*> GetAllMembers() override {
        vector<InSquadWarrior*> ans;
        for (auto &it: _children){
            //ans += it->GetAllMembers();
            AddVector(ans, it->GetAllMembers());
        }
        return ans;
    }

    ColoredString GetInfo() override {
        map<string, int> tmp = ReCount();
        ColoredString ans;
        ans.Add("\nStrength:\n");
        for (auto &it : tmp){
            ans.Add("  ");
            ans.Add(it.first, YELLOW);
            ans.Add(": ");
            ans.Add(it.second, GREEN);
            ans.Add("\n");
        }
        ans.Add("\nSquad members:\n");
        auto temp = GetAllMembers();
        for (auto &it : temp){
            ans.Add("->");
            ans.Add(it->HandleAction("Info"));
        }
        return ans;
    }
};


#endif //MYSTRATEGY_SQUAD_H