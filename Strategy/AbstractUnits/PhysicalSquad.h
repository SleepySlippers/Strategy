//
// Created by Arseny's on 01.05.2020.
//

#ifndef MYSTRATEGY_PHYSICALSQUAD_H
#define MYSTRATEGY_PHYSICALSQUAD_H


#include "../Properties/Movable.h"
#include "../Groups/Squad.h"
#include "../Properties/Named.h"
#include "../Map.h"

class PhysicalSquad : public Movable, public Named {
public:
    Squad *squad;

    PhysicalSquad(){
        squad = new Squad();
    }

    void AttackSquad(Squad* enemy){
        // TODO
        auto tmp = squad->GetAllMembers();
        for (auto &it : tmp){
            auto enm = enemy->GetAllMembers();
            if (enm.size()){
                (*enm[0]).GetDamage(it->attack);
            }
        }
    }

    bool CanHandle(int HandlerType) override {
        return Movable::CanHandle(HandlerType);
    }

    int &GetMyType() override {
        return Movable::GetMyType();
    }

    ColoredString HandleAction(const string &command) override{
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
                        trySquad->squad->Add(squad);
                        mainHandler->chosen = trySquad;
                        squad = nullptr;
                        DestroySelf();
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

    ColoredString Help() override {
        STANDARD_HELP_FUNCTION_BODY
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans = Movable::CommandsCanHandle();
        ans += Named::CommandsCanHandle();
        ans.push_back({"Attack", "Left/Right/Up/Down - attack an enemy in appropriate direction"});
        return ans;
    }

    void DeathCheck(){
        if (!squad->GetAllMembers().size()){
            DestroySelf();
        }
    }

    void DestroySelf(){
        globalMap->Delete(posX, posY);
    }

    ~PhysicalSquad() override{
        if (squad != nullptr) {
            delete squad;
        }
    }
};


#endif //MYSTRATEGY_PHYSICALSQUAD_H
