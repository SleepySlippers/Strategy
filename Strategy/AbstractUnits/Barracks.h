//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_BARRACKS_H
#define MYSTRATEGY_BARRACKS_H


#include <sstream>
#include "Building.h"
#include "../DrawTools/Colorize.h"
#include "../Map.h"
#include "Swordsman.h"
#include "../Factory/MyFactory.h"
#include "PhysicalSquad.h"

class Barracks : public Building {
public:
    Barracks(){
        appearance = 'B';
        color = BROWN;
        hp = 1300;
        defence = 80;
    }



    ColoredString HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "SpawnSwordsman"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            PhysicalSquad* tmp = owner->SpawnSwordsman();
            tmp->GetMyType() = GetMyType();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            //tmp->ChangeName(tryName("Swordsman"));
            return "Swordsman spawned with name " + tmp->GetName() + "\n";
        }
        return Building::HandleAction(command);
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Building::CommandsCanHandle();
        ans.push_back({"SpawnSwordsman", "- spawn an Swordsman to right cell if it's free"});
        return ans;
    }
};


#endif //MYSTRATEGY_BARRACKS_H
