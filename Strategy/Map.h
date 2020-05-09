//
// Created by Arseny's on 09.04.2020.
//



#ifndef STRATEGY_MAP_H
#define STRATEGY_MAP_H

class Map;
extern Map* globalMap;

const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 20;

class PhysicalObject;
class ColoredString;

class Map {
    PhysicalObject* map[MAP_HEIGHT][MAP_WIDTH];
public:

    Map();

    void Place(PhysicalObject *a);

    PhysicalObject* Get(int x, int y);

    void MapRecalc();

    bool IsEmpty(int x, int y);

    void Delete(int x, int y);

    void ReDrawMap();

    ColoredString GetMap();
};

#endif //STRATEGY_MAP_H
