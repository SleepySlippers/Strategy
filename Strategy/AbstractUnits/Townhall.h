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

class Townhall : public Building {
public:
    Townhall(){
        appearance = 'T';
        color = YELLOW;
    }

    string CommandsCanHandle() override {
        return "SpawnWorker\n";
    }

    std::string HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "SpawnWorker"){
            if (!globalMap->IsEmpty(posX + 1, posY)){
                return "Spawn place is taken\n";
            }
            Worker* tmp = globalSpawner->SpawnWorker();
            tmp->TeleportTo(posX + 1, posY);
            globalMap->Place(tmp);
            tmp->ChangeName(tryname("Worker"));
            //tmp->appearance = 'W';
            return "Worker spawned with name " + tmp->GetName() + "\n";
        }
        return NSC;
    }
};


#endif //MYSTRATEGY_TOWNHALL_H
