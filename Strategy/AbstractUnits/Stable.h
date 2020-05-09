//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_STABLE_H
#define MYSTRATEGY_STABLE_H


#include <sstream>
#include "Building.h"
#include "../DrawTools/Colorize.h"
#include "../Map.h"
#include "Swordsman.h"
#include "../Factory/MyFactory.h"

class Stable : public Building {
public:
    Stable(){
        appearance = 'S';
        color = BROWN;
    }



    ColoredString HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "SpawnHorseman"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            PhysicalSquad* tmp = owner->SpawnHorseman();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            //tmp->ChangeName(tryName("Horseman"));
            return "Horseman spawned with name " + tmp->GetName() + "\n";
        }
        return Building::HandleAction(command);
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Building::CommandsCanHandle();
        ans.emplace_back("SpawnHorseman", "- spawn a Horseman to right cell if it's free");
        return ans;
    }
};


#endif //MYSTRATEGY_STABLE_H
