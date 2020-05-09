//
// Created by Arseny's on 08.05.2020.
//

#include "Movable.h"

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

std::vector < Movable* > movables;

Direction StrToDir(const string &cmnd) {
    if (cmnd == "Left"){
        return Left;
    }
    if (cmnd == "Right"){
        return Right;
    }
    if (cmnd == "Up"){
        return Up;
    }
    if (cmnd == "Down"){
        return Down;
    }
    return Fail;
}

Movable::Movable() {
    movables.push_back(this);
}

Movable::~Movable() {
    auto i = movables.begin();
    for (; i != movables.end(); i++){
        if (*i == this){
            break;
        }
    }
    if (i != movables.end()) {
        movables.erase(i);
    }
}

void Movable::OnEndTurn() {
    RestoreMovePoints();
}

bool Movable::Move(Direction dir) {
    if (nowMovePoints > 0) {
        posX += dx[dir];
        posY += dy[dir];
        --nowMovePoints;
        return true;
    }
    return false;
}

void Movable::RestoreMovePoints() {
    nowMovePoints = maxMovePoints;
}

ColoredString Movable::HandleAction(const string &command) {
    std::istringstream in(command);
    std::string cmnd;
    in >> cmnd;
    if (cmnd == "Move"){
        in >> cmnd;
        if (nowMovePoints == 0){
            return "Not enough Move Points\n";
        }
        if (!globalMap->IsEmpty(posX + dx[StrToDir(cmnd)], posY + dy[StrToDir(cmnd)])){
            return "This place is taken\n";
        }
        if (StrToDir(cmnd) != Fail){
            Move(StrToDir(cmnd));
        } else {
            return "Wrong direction\n";
        }
        return "Moved to " + cmnd + "\n";
    }
    if (cmnd == "Info"){
        ColoredString ans;
        if (nowMovePoints == 0) {
            ans.Add(std::to_string(nowMovePoints), RED);
        } else {
            ans.Add(std::to_string(nowMovePoints), GREEN);
        }
        ans.Add(" / ");
        ans.Add(std::to_string(maxMovePoints), YELLOW);
        ans.Add(" move points. ");
        if (nowMovePoints == 0) {
            ans.Add("EndTurn", YELLOW);
            ans.Add(" to restore it.");
        }
        ans.Add("\n");
        ans.Add(PhysicalObject::HandleAction("Info"));
        //ans <<  << " move points left\nWill have " <<  << " move points on the next move\n";
        // TODO
        return ans;
    }
    if (cmnd == "Help" || cmnd == "help"){
        return Help();
    }
    return NSC;
}

ColoredString Movable::Help() {
    STANDARD_HELP_FUNCTION_BODY
}

std::vector<pair<string, string>> Movable::CommandsCanHandle() {
    std::vector<pair<string, string>> ans = PhysicalObject::CommandsCanHandle();
    ans.emplace_back("Move", "Left/Right/Up/Down");
    if (NEED_INFO) {
        ans.emplace_back("Info", "- full information");
    }
    return ans;
}
