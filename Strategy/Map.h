//
// Created by Arseny's on 09.04.2020.
//


class Map;
extern Map* globalMap;

#ifndef STRATEGY_MAP_H
#define STRATEGY_MAP_H

#include <cstdlib>
#include "Properties/PhysicalObject.h"
#include "Colorize.h"
#include "ColoredString.h"
//#include "MainHandler.h"

const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 20;



class Map {
    PhysicalObject* map[MAP_HEIGHT][MAP_WIDTH];
public:

    Map(){
        for (auto & i : map){
            for (auto & j : i){
                j = nullptr;
            }
        }
    }

    void Place(PhysicalObject *a){
        map[a->posY][a->posX] = a;
    }

    PhysicalObject* Get(int x, int y){
        return map[y][x];
    }

    void MapRecalc(){
        for (int i = 0; i < MAP_HEIGHT; i++){
            for (int j = 0; j < MAP_WIDTH; j++){
                if (map[i][j] != nullptr){
                    if (map[i][j]->posY != i || map[i][j]->posX != j){
                        if (map[map[i][j]->posY][map[i][j]->posX] == nullptr){
                            map[map[i][j]->posY][map[i][j]->posX] = map[i][j];
                            map[i][j] = nullptr;
                        }
                    }
                }
            }
        }
    }

    bool IsEmpty(int x, int y){
        return map[y][x] == nullptr;
    }

    void Delete(int x, int y){
        if (!IsEmpty(x, y)) {
            delete map[y][x];
            map[y][x] = nullptr;
        }
    }

    void ReDrawMap(){
        MapRecalc();
        system("cls");
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (!IsEmpty(j, i)){
                    SetColor(map[i][j]->color, map[i][j]->fonColor);
                    std::cout << map[i][j]->appearance;
                    SetColor(15, 0);
                } else {
                    SetColor(15, 0);
                    std::cout << '.';
                    SetColor(15, 0);
                }
            }
            std::cout << "\n";
        }
    }

    ColoredString GetMap(){
        MapRecalc();
        ColoredString ans;
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (!IsEmpty(j, i)){
                    //SetColor(map[i][j]->color, map[i][j]->fonColor);
                    //std::cout << map[i][j]->appearance;
                    //SetColor(15, 0);
                    ans.Add(string(1, map[i][j]->appearance), map[i][j]->color, map[i][j]->fonColor);
                } else {
                    //SetColor(15, 0);
                    //std::cout << '.';
                    //SetColor(15, 0);
                    ans.Add(".");
                }
            }
            //std::cout << "\n";
            ans.Add("\n");
        }
        return ans;
    }


};

#endif //STRATEGY_MAP_H
