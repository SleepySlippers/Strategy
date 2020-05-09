//
// Created by Arseny's on 09.05.2020.
//

#include "Worker.h"

#include "Barracks.h"
#include "Stable.h"
#include "Archery.h"

Worker::Worker() {
    appearance = 'W';
    color = WHITE;
}

ColoredString Worker::HandleAction(const string &command) {
    std::istringstream in(command);
    std::string cmnd;
    in >> cmnd;
    if (cmnd == "Build"){
        in >> cmnd;
        if (!globalMap->IsEmpty(posX + 1, posY)){
            return "Spawn place is taken\n";
        }
        Building *tmp;
        if (cmnd == "Barracks"){
            tmp = owner->SpawnBarracks();
            tmp->owner = owner;
        } else if (cmnd == "Stable"){
            tmp = owner->SpawnStable();
            tmp->owner = owner;
        } else if (cmnd == "Archery"){
            tmp = owner->SpawnArchery();
            tmp->owner = owner;
        } else {
            return NSC;
        }
        tmp->GetMyType() = GetMyType();
        tmp->TeleportTo(posX + 1, posY);
        globalMap->Place(tmp);
        tmp->ChangeName(tryName(cmnd));
        //tmp->appearance = 'B';
        nowMovePoints = 0;
        return cmnd + " spawned with name " + tmp->GetName() + "\n";
    }
    return Unit::HandleAction(command);
    return NSC;
}

std::vector<pair<string, string>> Worker::CommandsCanHandle() {
    std::vector<pair<string, string>> ans = Unit::CommandsCanHandle();
    ans.push_back({"Build Barracks", "- build an Barracks in right cell if it's free"});
    ans.push_back({"Build Stable", "- build an Stable in right cell if it's free"});
    ans.push_back({"Build Archery", "- build an Archery in right cell if it's free"});
    return ans;
}
