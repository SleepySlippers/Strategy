//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_BARRACKS_H
#define MYSTRATEGY_BARRACKS_H


#include <sstream>
#include "Building.h"
#include "../Colorize.h"
#include "../Map.h"
#include "Swordman.h"
#include "../Factory/Spawner.h"

class Barracks : public Building {
public:
    Barracks(){
        appearance = 'B';
        color = BROWN;
    }

    string CommandsCanHandle() override {
        return "SpawnSwordman\n";
    }

    std::string HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "SpawnSwordman"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            Swordman* tmp = globalSpawner->SpawnSwordman();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            tmp->ChangeName(tryname("Swordman"));
            return "Swordman spawned with name " + tmp->GetName() + "\n";
        }
        return NSC;
    }
};


#endif //MYSTRATEGY_BARRACKS_H
