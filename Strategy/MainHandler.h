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
#include "MyUtilite.h"

class MainHandler : public Handleable {
public:
    Named* chosen = nullptr;
    int chosenx = 0;
    int choseny = 0;
    //int lastfon;
    //Map* globalMap;

    MainHandler() {

    }

    ColoredString HandleAction(const std::string &command) override {
        std::istringstream in(command);
        std::string cmnd;
        in >> cmnd;
        if (cmnd == "Exit"){
            exit(0);
        }
        /*if (cmnd == "Chosen"){
            if (chosen == nullptr){
                return "Nobody is chosen\n";
            } else {
                return chosen->GetName() + " is chosen\n";
            }
        }*/
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
                //if (chosen != nullptr){
                    //dynamic_cast<PhysicalObject*>(chosen)->fonColor = lastfon;
                //}
                chosen = names[cmnd];
                //lastfon = dynamic_cast<PhysicalObject*>(chosen)->fonColor;
                //dynamic_cast<PhysicalObject*>(chosen)->fonColor = 13;
                auto tmp = dynamic_cast<PhysicalObject*>(chosen);
                chosenx = tmp->posX;
                choseny = tmp->posY;
                return cmnd + " is chosen\n";
            } else {
                return "Wrong name\n";
            }
        }
        if (cmnd == "ChangeName"){
            in >> cmnd;
            if (cmnd.size() > 10){
                return "Too long\n";
            }
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
            auto tmp = dynamic_cast<Handleable *>(chosen)->HandleAction(command);
            chosenx = dynamic_cast<PhysicalObject *>(chosen)->posX;
            choseny = dynamic_cast<PhysicalObject *>(chosen)->posY;
            return tmp;
        }
        return NSC;
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans;
        ans.emplace_back("ShowAllNames", "- print all list of names of objects on board");
        ans.emplace_back("Choose", "%name% - choose object with certain %name%");
        ans.emplace_back("ChangeName", "%newname% - change object name to %newname% if object with %newname% not exist. Max %newname% length is 10.");
        ans.emplace_back("EndTurn", "- end turn and restore all move points");
        ans.emplace_back("Exit", "- close game");
        if (chosen != nullptr){
            ans += chosen->CommandsCanHandle();
        }
        return ans;
    }

    ColoredString Help() override {
        ColoredString ans;
        ans.put('\0');
        ans.Add(" Global Commands: \n");
        int i = 0;
        auto tmp = CommandsCanHandle();
        for (; i < tmp.size(); i++){
            ans.Add("[", BLUE);
            ans.Add(i + 1, BLUE);
            ans.Add("]", BLUE);
            ans.Add(" " );
            ans.Add(tmp[i].first, YELLOW);
            ans.Add(" ");
            ans.Add(tmp[i].second);
            ans.Add("\n");
            if (tmp[i].first == "Exit"){
                if (chosen != nullptr) {
                    ans.put('\0');
                    ans.Add(" ");
                    ans.Add("Object", BLACK, 13);
                    ans.Add(" Commands: \n");
                }
            }
        }
        if (chosen != nullptr){
            ColoredString tmp = chosen->HandleAction("Info");
            if (tmp != NSC){
                ans.put('\0');
                ans.Add(" ");
                ans.Add("Object", BLACK, 13);
                ans.Add(" Info: \n");
                ans.Add(tmp);
            }
        }
        return ans;
    }

    /*ColoredString CommandsCanHandle() override {
        ColoredString ans;
        ans.put('\0');
        ans.Add(" Global Commands: \n");
        //ans << "CreateUnit\nShowAllNames\nChoose %name%\nChosen\nChangeName\nEndTurn\nExit\n";
        ans.Add("ShowAllNames\nChoose %name%\nChosen\nChangeName\nEndTurn\nExit\n");
        if (chosen != nullptr) {
            ans.put('\0');
            ans.Add(" ");
            ans.Add("Object", BLACK, 13);
            ans.Add(" Commands: \n");
            ans.Add(dynamic_cast<Handleable *>(chosen)->CommandsCanHandle());
        }
        return ans;
    }*/
};

#endif //STRATEGY_MAINHANDLER_H
