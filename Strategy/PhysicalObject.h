//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_PHYSICALOBJECT_H
#define STRATEGY_PHYSICALOBJECT_H

//#include "Map.h"

class PhysicalObject {
public:
    int posX = 0;
    int posY = 0;
    char appearnace = 'A';
    int color = 15;

    std::pair < int, int > GetPosAsPair() const {
        return std::make_pair(posX, posY);
    }
};


#endif //STRATEGY_PHYSICALOBJECT_H
