//
// Created by Arseny's on 09.05.2020.
//

#include "Squad.h"

#include <algorithm>
#include "../MyUtility.h"
#include "InSquadWarrior.h"

void Squad::Add(Group *group) {
    _children.push_back(group);
    group->SetParent(this);
}

void Squad::Remove(Group *group) {
    _children.remove(group);
    group->SetParent(nullptr);
}

map<string, int> Squad::ReCount() {
    map<string, int> ans;
    for (auto it: _children){
        //ans.merge(it->ReCount());
        //ans += it->ReCount();
        AddMap(ans, it->ReCount());
    }
    return ans;
}

bool cmp(InSquadWarrior *a, InSquadWarrior *b){
    if (a->attackRange < b->attackRange) return true;
    return a->attackRange == b->attackRange && a->hp > b->hp;
}

vector<InSquadWarrior *> Squad::GetAllMembers() {
    vector<InSquadWarrior*> ans;
    for (auto &it: _children){
        //ans += it->GetAllMembers();
        AddVector(ans, it->GetAllMembers());
    }
    sort(ans.begin(), ans.end(), cmp);
    return ans;
}

ColoredString Squad::GetInfo() {
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
