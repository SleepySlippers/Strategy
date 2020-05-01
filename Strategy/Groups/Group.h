//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_GROUP_H
#define MYSTRATEGY_GROUP_H


#include "../ColoredString.h"

#include <map>
using std::map;

class InSquadWarrior;

class Group {
protected:
    Group *_parent = nullptr;
public:
    virtual ~Group()= default;
    void SetParent(Group *parent) {
        this->_parent = parent;
    }

    Group *GetParent() const {
        return this->_parent;
    }

    virtual void Add(Group *group) {}
    virtual void Remove(Group *group) {}

    virtual bool IsComposite() const {
        return false;
    }

    virtual std::vector<InSquadWarrior*> GetAllMembers() = 0;

    virtual map<string, int> ReCount() = 0;

    virtual ColoredString GetInfo() = 0;
};


#endif //MYSTRATEGY_GROUP_H
