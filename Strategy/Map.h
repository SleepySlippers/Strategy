//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_MAP_H
#define STRATEGY_MAP_H

#include <cstdlib>
#include "PhysicalObject.h"
#include "Colorize.h"

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

    void Place(PhysicalObject *a, int x, int y){
        map[y][x] = a;
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
        return map[x][y] == nullptr;
    }

    void ReDrawMap(){
        MapRecalc();
        system("cls");
        for (int i = 0; i < MAP_HEIGHT; i++) {
            for (int j = 0; j < MAP_WIDTH; j++) {
                if (!IsEmpty(i, j)){
                    SetColor(map[i][j]->color, 0);
                    std::cout << map[i][j]->appearnace;
                    SetColor(15, 0);
                } else {
                    SetColor(15, 0);
                    std::cout << ' ';
                    SetColor(15, 0);
                }
            }
            std::cout << "\n";
        }
    }
};

#endif //STRATEGY_MAP_H
