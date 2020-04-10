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

    string CommandsCanHandle() override {
        return "BuildBarracks\n" + Unit::CommandsCanHandle();
    }

    std::string HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "BuildBarracks"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            Barracks* tmp = globalSpawner->SpawnBarracks();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            tmp->ChangeName(tryname("Barracks"));
            //tmp->appearance = 'B';
            return "Barracks spawned with name " + tmp->GetName() + "\n";
        }
        return Unit::HandleAction(command);
        return NSC;
    }
};


#endif //MYSTRATEGY_WORKER_H
