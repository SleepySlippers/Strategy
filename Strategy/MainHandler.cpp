//
// Created by Arseny's on 09.05.2020.
//

#include "MainHandler.h"

#include <sstream>

MainHandler::MainHandler(int type) : Handleable(type) {

}

ColoredString MainHandler::HandleAction(const string &command) {
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
        for (const auto& it : names){
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
            if (tmp != nullptr) {
                chosenX = tmp->posX;
                chosenY = tmp->posY;
            }
            return cmnd + " is chosen\n";
        } else {
            return "Wrong name\n";
        }
    }
    if (cmnd == "ChangeName" && CanHandle(chosen->GetMyType())){
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
        if (cmnd == "Info"){
            return dynamic_cast<Handleable *>(chosen)->HandleAction(command);
        }
#ifndef _DEB_CAN_CONTROL_ENEMY
        if (chosen->CanHandle(GetMyType())) {
#endif
            auto tmp = dynamic_cast<Handleable *>(chosen)->HandleAction(command);
            if (chosen != nullptr) {
                auto temp = dynamic_cast<PhysicalObject *>(chosen);
                if (temp != nullptr) {
                    chosenX = temp->posX;
                    chosenY = temp->posY;
                }
            }
            return tmp;
#ifndef _DEB_CAN_CONTROL_ENEMY
        }
#endif
        return NSC;
    }
    return NSC;
}

std::vector<std::pair<std::string, std::string>> MainHandler::CommandsCanHandle() {
    std::vector<std::pair<std::string, std::string>> ans;
    //ans.emplace_back("ShowAllNames", "- print all list of names of objects on board");
    //ans.emplace_back("Choose", "%name% - choose object with certain %name%");
    //ans.emplace_back("ChangeName", "%newname% - change object name to %newname% if object with %newname% not exist. Max %newname% length is 10.");
    ans.emplace_back("EndTurn", "- end turn and restore all move points");
    ans.emplace_back("Exit", "- close game");
    if (chosen != nullptr) {
#ifndef _DEB_CAN_CONTROL_ENEMY
        if (chosen->CanHandle(GetMyType())) {
#endif
            //ans += chosen->CommandsCanHandle();
            AddVector(ans, chosen->CommandsCanHandle());
#ifndef _DEB_CAN_CONTROL_ENEMY
        }
#endif
    }
    return ans;
}

ColoredString MainHandler::Help() {
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
            if (chosen != nullptr && chosen->CommandsCanHandle().size()) {
#ifndef _DEB_CAN_CONTROL_ENEMY
                if (chosen->CanHandle(GetMyType())) {
#endif
                    ans.put('\0');
                    ans.Add(" ");
                    ans.Add("Object", BLACK, 13);
                    ans.Add(" Commands: \n");
#ifndef _DEB_CAN_CONTROL_ENEMY
                }
#endif
            }
        }
    }
    if (chosen != nullptr){
        ColoredString temp = chosen->HandleAction("Info");
        if (temp != NSC){
            ans.put('\0');
            ans.Add(" ");
            ans.Add("Object", BLACK, 13);
            ans.Add(" Info: \n");
            ans.Add(temp);
        }
    }
    return ans;
}
