//
// Created by Arseny's on 08.05.2020.
//

#include "Named.h"

#include <iostream>
#include "../Factory/Spawner.h"

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

string nameParts[PARTS_COUNT] = {"ibn", "ar", "se", "ny", "em", "il", "ta", "gir", "car", "rot", \
                        "nik", "it", "um", "to", "rist"};

string Named::GetName() const {
    return name;
}

bool Named::ChangeName(const string &newname) {
    if (names.count(newname))
        return false;
    names[newname] = this;
    names.erase(name);
    name = newname;
    return true;
}

Named::Named() {
    for (int i = 0; i < 3; i++){
        name += nameParts[rand() % PARTS_COUNT];
    }
    ChangeName(tryName(name));
}

ColoredString Named::HandleAction(const string &command) {
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

std::vector<pair<string, string>> Named::CommandsCanHandle() {
    std::vector<pair<string, string>> ans;
    if (NEED_INFO) {
        ans.emplace_back("Info", "- full information");
    }
    return ans;
}
