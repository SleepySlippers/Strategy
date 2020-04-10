//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_PHYSICALOBJECT_H
#define STRATEGY_PHYSICALOBJECT_H

#include <utility>

class PhysicalObject {
public:
    int posX = 0;
    int posY = 0;
    char appearance = 'A';
    int color = 15;
    int foncolor = 0;

    std::pair < int, int > GetPosAsPair() const {
        return std::make_pair(posX, posY);
    }

    void TeleportTo(int x, int y){
        posX = x;
        posY = y;
    }
};


#endif //STRATEGY_PHYSICALOBJECT_H
