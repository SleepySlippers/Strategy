//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_MOVABLE_H
#define STRATEGY_MOVABLE_H


#include <sstream>
#include <vector>
#include "PhysicalObject.h"
#include "Handleable.h"
#include "../Map.h"

enum Direction{
    Right,
    Up,
    Left,
    Down,
    Fail
};

Direction StrToDir(const string& cmnd);

//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, -1, 0, 1};
extern int dx[4];
extern int dy[4];

class Movable;
extern std::vector < Movable* > movables;

class Movable : public PhysicalObject {
public:
    int maxMovePoints = 3;
    int nowMovePoints = 0;

    Movable();

    virtual ~Movable();

    virtual void OnEndTurn();

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

    virtual bool Move(Direction dir);

    virtual void RestoreMovePoints();

    ColoredString HandleAction(const std::string &command) override;

    ColoredString Help() override;

    std::vector<pair<string, string>> CommandsCanHandle() override;

    /*ColoredString CommandsCanHandle() override{
        return "Move Left/Right/Top/Bottom\nInfo\n";
    }*/
};


#endif //STRATEGY_MOVABLE_H
