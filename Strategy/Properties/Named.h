//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_NAMED_H
#define STRATEGY_NAMED_H

#include <unordered_map>
#include "Handleable.h"

using std::string;

class Named;
extern std::unordered_map<string, Named*> names;

string tryName(const string &nm);

#define PARTS_COUNT (15)
extern string nameParts[PARTS_COUNT];

class Spawner;

class Named : public Handleable {
    string name;
public:
    Spawner *owner = nullptr;
    string GetName() const;

    bool ChangeName(const string &newname);

    Named();

    /*virtual ColoredString HandleAction(const std::string &command) override = 0;

    virtual ColoredString CommandsCanHandle() override = 0;*/

    ColoredString HandleAction(const string &command) override;

    std::vector<pair<string, string>> CommandsCanHandle() override;

    virtual ~Named()= default;
};


#endif //STRATEGY_NAMED_H
