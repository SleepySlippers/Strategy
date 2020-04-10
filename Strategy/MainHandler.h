//
// Created by Arseny's on 09.04.2020.
//

class MainHandler;
extern MainHandler* mainHandler;

#ifndef STRATEGY_MAINHANDLER_H
#define STRATEGY_MAINHANDLER_H


//#include "Properties/Handleable.h"
//#include "Map.h"
#include "Properties/Named.h"
#include "Properties/Movable.h"
//#include "AbstractUnits/Unit.h"
#include <sstream>

class MainHandler : public Handleable {
public:
    Named* chosen = nullptr;
    int lastfon;
    //Map* globalMap;

    MainHandler() {

    }

    string HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "Exit"){
            exit(0);
        }
        if (cmnd == "Chosen"){
            if (chosen == nullptr){
                return "Nobody is chosen\n";
            } else {
                return chosen->GetName() + " is chosen\n";
            }
        }
        if (cmnd == "ShowAllNames"){
            std::ostringstream ans;
            for (auto it : names){
                ans << it.first << std::endl;
            }
            return ans.str();
        }
        if (cmnd == "Choose"){
            in >> cmnd;
            if (names.count(cmnd)){
                if (chosen != nullptr){
                    dynamic_cast<PhysicalObject*>(chosen)->foncolor = lastfon;
                }
                chosen = names[cmnd];
                lastfon = dynamic_cast<PhysicalObject*>(chosen)->foncolor;
                dynamic_cast<PhysicalObject*>(chosen)->foncolor = 13;
                return cmnd + " is chosen\n";
            } else {
                return "Wrong name\n";
            }
        }
        if (cmnd == "ChangeName"){
            in >> cmnd;
            if (!chosen->ChangeName(cmnd)){
                return "Cant change name\n";
            } else {
                return "Name changed to " + cmnd + "\n";
            }
        }
/*        if (cmnd == "CreateUnit"){
            Unit* un = new Unit();
            globalMap->Place(un);
            return "Unit created with name " + un->GetName() + "\n";
        }*/
        if (cmnd == "Help" || cmnd == "help"){
            return Help();
        }
        if (cmnd == "EndTurn"){
            for (auto it : movables){
                it->OnEndTurn();
            }
            return "Turn ended\n";
        }
        if (chosen != nullptr) {
            string tmp = dynamic_cast<Handleable *>(chosen)->HandleAction(command);
            return tmp;
        }
        return NSC;
    }

    string CommandsCanHandle() override {
        std::ostringstream ans;
        if (chosen != nullptr) {
            ans << "Object commands:\n";
            ans << dynamic_cast<Handleable *>(chosen)->CommandsCanHandle();
        }
        ans << "Global Commands:\n";
        //ans << "CreateUnit\nShowAllNames\nChoose %name%\nChosen\nChangeName\nEndTurn\nExit\n";
        ans << "ShowAllNames\nChoose %name%\nChosen\nChangeName\nEndTurn\nExit\n";
        return ans.str();
    }
};

#endif //STRATEGY_MAINHANDLER_H
