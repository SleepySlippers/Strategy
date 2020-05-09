//
// Created by Arseny's on 09.05.2020.
//

#include <cstdlib>

#include "Map.h"
#include "Properties/PhysicalObject.h"
#include "DrawTools/Colorize.h"
#include "DrawTools/ColoredString.h"

Map::Map() {
    for (auto & i : map){
        for (auto & j : i){
            j = nullptr;
        }
    }
}

void Map::Place(PhysicalObject *a) {
    map[a->posY][a->posX] = a;
}

PhysicalObject *Map::Get(int x, int y) {
    return map[y][x];
}

void Map::MapRecalc() {
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

bool Map::IsEmpty(int x, int y) {
    return map[y][x] == nullptr;
}

void Map::Delete(int x, int y) {
    if (!IsEmpty(x, y)) {
        delete map[y][x];
        map[y][x] = nullptr;
    }
}

void Map::ReDrawMap() {
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

ColoredString Map::GetMap() {
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
