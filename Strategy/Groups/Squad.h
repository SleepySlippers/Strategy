//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_SQUAD_H
#define MYSTRATEGY_SQUAD_H

#include <list>
#include "Group.h"
#include <map>
#include <vector>

class Squad : public Group {
protected:
    std::list<Group*> _children;
public:
    void Add(Group *group) override;

    void Remove(Group *group) override;

    bool IsComposite() const override {
        return true;
    }

    map<string, int> ReCount() override;

    std::vector<InSquadWarrior*> GetAllMembers() override;

    ColoredString GetInfo() override;
};


#endif //MYSTRATEGY_SQUAD_H
