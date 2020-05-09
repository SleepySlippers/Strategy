//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_TOWNHALL_H
#define MYSTRATEGY_TOWNHALL_H


#include "../Factory/Spawner.h"
#include "../Map.h"
#include "Worker.h"
#include "Building.h"
#include <sstream>

class TownHall : public Building {
public:
    TownHall(){
        appearance = 'T';
        color = YELLOW;
    }

    ColoredString HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "SpawnWorker"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            Worker* tmp = owner->SpawnWorker();
            tmp->owner = owner;
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            tmp->ChangeName(tryName("Worker"));
            //tmp->appearance = 'W';
            ColoredString ans;
            ans.Add("Worker spawned with name ");
            ans.Add(tmp->GetName(), YELLOW);
            ans.Add("\n");
            return ans;//"Worker spawned with name " + tmp->GetName() + "\n";
        }
        return Building::HandleAction(command);
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Building::CommandsCanHandle();
        ans.push_back({"SpawnWorker", "- spawn an Worker to right cell if it's free"});
        return ans;
    }
};


#endif //MYSTRATEGY_TOWNHALL_H
