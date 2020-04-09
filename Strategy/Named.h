//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_NAMED_H
#define STRATEGY_NAMED_H

#include <unordered_map>
#include <iostream>

using std::string;

class Named;
std::unordered_map<string, Named*> names;

#define PARTSCOUNT (15)
string nameparts[PARTSCOUNT] = {"ibn", "ar", "se", "ny", "em", "il", "ta", "gir", "car", "rot", \
                        "nik", "it", "um", "to", "rist"};


/// must be Handlable
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
        names[name] = this;
    }
};


#endif //STRATEGY_NAMED_H
