//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_MOVABLE_H
#define STRATEGY_MOVABLE_H


#include <sstream>
#include <vector>
#include "PhysicalObject.h"
#include "Handleable.h"

enum Direction{
    Right,
    Up,
    Left,
    Down,
    Fail
};

Direction StrToDir(const string& cmnd){
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

class Movable;
std::vector < Movable* > movables;

class Movable : public PhysicalObject, public Handleable {
public:
    int maxMovePoints = 3;
    int nowMovePoints = 0;

    Movable(){
        movables.push_back(this);
    }

    virtual void OnEndTurn(){
        RestoreMovePoints();
    }

    /*  зачем писать все эти методы если можно сделать поля public
    void SetMaxMovePoints(int x){
        maxMovePoints = x;
    }

    int GetMaxMovePoints() const{
        return maxMovePoints;
    }

    void SetNowMovePoints(int x){
        nowMovePoints = x;
    }

    int GetNowMovePoints() const{
        return nowMovePoints;
    }*/

    virtual bool Move(Direction dir){
        if (nowMovePoints > 0) {
            posX += dx[dir];
            posY += dy[dir];
            --nowMovePoints;
            return true;
        }
        return false;
    }

    virtual void RestoreMovePoints(){
        nowMovePoints = maxMovePoints;
    }

    std::string HandleAction(const std::string &command) override{
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
            }
            return "Moved to " + cmnd + "\n";
        }
        if (cmnd == "Info"){
            std::ostringstream ans;
            ans << nowMovePoints << " move points left\nWill have " << maxMovePoints << " move points on the next move\n";
            ans << "Position x: " << posX << " y: " << posY << "\n";
            return ans.str();
        }
        if (cmnd == "Help" || cmnd == "help"){
            return Help();
        }
        return NSC;
    }

    std::string CommandsCanHandle() override{
        return "Move Left/Right/Top/Bottom\nInfo\n";
    }
};


#endif //STRATEGY_MOVABLE_H
