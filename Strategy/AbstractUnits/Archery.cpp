//
// Created by Arseny's on 09.05.2020.
//

#include "Archery.h"

#include <sstream>
#include "../Factory/MyFactory.h"
#include "PhysicalSquad.h"
#include "../Map.h"

Archery::Archery() {
    appearance = 'A';
    color = BROWN;
    defence = 60;
    hp = 1000;
}

ColoredString Archery::HandleAction(const string &command) {
    std::istringstream in(command);
    std::string cmnd;
    in >> cmnd;
    if (cmnd == "SpawnArcher"){
        if (!globalMap->IsEmpty(posX + 1, posY)){
            return "Spawn place is taken\n";
        }
        PhysicalSquad* tmp = owner->SpawnArcher();
        tmp->GetMyType() = GetMyType();
        tmp->TeleportTo(posX + 1, posY);
        globalMap->Place(tmp);
        //tmp->ChangeName(tryName("Archer"));
        return "Archer spawned with name " + tmp->GetName() + "\n";
    }
    return Building::HandleAction(command);
}

std::vector<pair<string, string>> Archery::CommandsCanHandle() {
    std::vector<pair<string, string>> ans = Building::CommandsCanHandle();
    ans.emplace_back("SpawnArcher", "- spawn an Archer to right cell if it's free");
    return ans;
}
