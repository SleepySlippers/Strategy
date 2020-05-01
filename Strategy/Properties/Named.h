//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_NAMED_H
#define STRATEGY_NAMED_H

#include <unordered_map>
#include <iostream>
#include "Handleable.h"

using std::string;

class Named;
std::unordered_map<string, Named*> names;

string tryName(const string &nm){
    //if (names.count(nm)){
        for (int i = 1; true; i++){
            if (!names.count(nm + std::to_string(i))){
                return nm + std::to_string(i);
            }
        }
    //}
    //return nm;
}

#define PARTSCOUNT (15)
string nameparts[PARTSCOUNT] = {"ibn", "ar", "se", "ny", "em", "il", "ta", "gir", "car", "rot", \
                        "nik", "it", "um", "to", "rist"};


class Named : public Handleable {
    string name;
public:
    string GetName() const{
        return name;
    }

    bool ChangeName(const string &newname){
        if (names.count(newname))
            return false;
        names[newname] = this;
        names.erase(name);
        name = newname;
        return true;
    }

    Named(){
        for (int i = 0; i < 3; i++){
            name += nameparts[rand() % PARTSCOUNT];
        }
        ChangeName(tryName(name));
    }

    /*virtual ColoredString HandleAction(const std::string &command) override = 0;

    virtual ColoredString CommandsCanHandle() override = 0;*/

    ColoredString HandleAction(const string &command) override{
        if (command == "Info"){
            ColoredString tmp;
            tmp.Add("My name is ");
            tmp.Add(name, YELLOW);
            tmp.Add("\n");
            return tmp;
        } else {
            return NSC;
        }
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans;
        if (NEED_INFO) {
            ans.emplace_back("Info", "- full information");
        }
        return ans;
    }

    virtual ~Named()= default;;
};


#endif //STRATEGY_NAMED_H
