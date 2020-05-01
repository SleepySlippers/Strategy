//
// Created by Arseny's on 10.04.2020.
//

#ifndef MYSTRATEGY_WORKER_H
#define MYSTRATEGY_WORKER_H


#include "Unit.h"
#include "Barracks.h"

class Worker : public Unit {
public:
    Worker(){
        appearance = 'W';
        color = WHITE;
    }

    ColoredString HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "BuildBarracks"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            Barracks* tmp = mySpawner->SpawnBarracks();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            tmp->ChangeName(tryName("Barracks"));
            //tmp->appearance = 'B';
            nowMovePoints = 0;
            return "Barracks spawned with name " + tmp->GetName() + "\n";
        }
        return Unit::HandleAction(command);
        return NSC;
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Unit::CommandsCanHandle();
        ans.push_back({"BuildBarracks", "- build an Barracks in right cell if it's free"});
        return ans;
    }
};


#endif //MYSTRATEGY_WORKER_H
