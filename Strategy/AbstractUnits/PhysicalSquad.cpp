//
// Created by Arseny's on 08.05.2020.
//

#include "PhysicalSquad.h"


#include "../Map.h"
#include "../Groups/Squad.h"


void PhysicalSquad::AttackSquad(Squad *enemy) {
    // TODO
    auto tmp = squad->GetAllMembers();
    for (auto &it : tmp){
        auto enm = enemy->GetAllMembers();
        if (enm.size()){
            (*enm[0]).GetDamage(it->attack);
        }
    }
}

PhysicalSquad::~PhysicalSquad() {
    if (squad != nullptr) {
        delete squad;
    }
}

void PhysicalSquad::DestroySelf() {
    globalMap->Delete(posX, posY);
}

void PhysicalSquad::DeathCheck() {
    if (!squad->GetAllMembers().size()){
        DestroySelf();
    }
}

std::vector<pair<string, string>> PhysicalSquad::CommandsCanHandle() {
    std::vector<pair<string, string>> ans = Movable::CommandsCanHandle();
    ans += Named::CommandsCanHandle();
    ans.push_back({"Attack", "Left/Right/Up/Down - attack an enemy in appropriate direction"});
    return ans;
}

ColoredString PhysicalSquad::Help() {
    STANDARD_HELP_FUNCTION_BODY
}

ColoredString PhysicalSquad::HandleAction(const string &command) {
    std::istringstream in(command);
    std::string cmnd;
    in >> cmnd;
    if (cmnd == "Info"){
        ColoredString tmp;
        tmp.Add(Movable::HandleAction("Info"));
        tmp.Add(Named::HandleAction("Info"));
        tmp.Add(squad->GetInfo());
        return tmp;
    }
    if (cmnd == "Move") {
        in >> cmnd;
        if (nowMovePoints == 0) {
            return "Not enough Move Points\n";
        }
        if (StrToDir(cmnd) != Fail) {
            if (!globalMap->IsEmpty(posX + dx[StrToDir(cmnd)], posY + dy[StrToDir(cmnd)])) {
                PhysicalSquad *trySquad = dynamic_cast<PhysicalSquad *>(
                        globalMap->Get(posX + dx[StrToDir(cmnd)], posY + dy[StrToDir(cmnd)])
                );
                if (trySquad != nullptr && (trySquad->CanHandle(GetMyType()))) {
                    // TODO maybe wrong
                    squad->Add(trySquad->squad);
                    trySquad->squad = nullptr;
                    trySquad->DestroySelf();
                    Movable::HandleAction(command);
                    //trySquad->squad->Add(squad);
                    //mainHandler->chosen = trySquad;
                    //squad = nullptr;
                    //DestroySelf();
                    return "Merged\n";
                }
            }
        } else {
            return Movable::HandleAction(command);
        }
    }
    if (cmnd == "Attack"){
        in >> cmnd;
        if (nowMovePoints == 0) {
            return "Not enough Move Points\n";
        }
        if (StrToDir(cmnd) != Fail) {
            if (!globalMap->IsEmpty(posX + dx[StrToDir(cmnd)], posY + dy[StrToDir(cmnd)])) {
                PhysicalSquad *trySquad = dynamic_cast<PhysicalSquad *>(
                        globalMap->Get(posX + dx[StrToDir(cmnd)], posY + dy[StrToDir(cmnd)])
                );
                if (trySquad != nullptr && !(trySquad->CanHandle(GetMyType()))) {
                    AttackSquad(trySquad->squad);
                    trySquad->DeathCheck();
                    nowMovePoints = 0;
                    return "Attacked\n";
                }
                return "Target is not enemy squad\n";
            } else {
                return "Cant attack an empty place\n";
            }
        } else {
            return "Wrong direction\n";
        }
    }
    ColoredString ans;
    ColoredString tmp;
    tmp = Movable::HandleAction(command);
    if (tmp != NSC){
        ans.Add(tmp);
    }
    tmp = Named::HandleAction(command);
    if (tmp != NSC){
        ans.Add(tmp);
    }
    if (!ans.size()){
        return NSC;
    }
    return ans;
}

int &PhysicalSquad::GetMyType() {
    return Movable::GetMyType();
}

PhysicalSquad::PhysicalSquad() {
    squad = new Squad();
    ChangeName(tryName("Squad"));
    appearance = 'Q';
}

bool PhysicalSquad::CanHandle(int HandlerType) {
    return Movable::CanHandle(HandlerType);
}
