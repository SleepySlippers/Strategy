//
// Created by Arseny's on 08.04.2020.
//

#ifndef STRATEGY_PHYSICALOBJECT_H
#define STRATEGY_PHYSICALOBJECT_H

#include <utility>
#include "Handleable.h"

class PhysicalObject : public Handleable {
public:
    int posX = 0;
    int posY = 0;
    char appearance = 'A';
    int color = 15;
    int fonColor = 0;

    std::pair < int, int > GetPosAsPair() const {
        return std::make_pair(posX, posY);
    }

    void TeleportTo(int x, int y){
        posX = x;
        posY = y;
    }

    ColoredString HandleAction(const string &command) override{
        if (command == "Info"){
            ColoredString tmp;
            tmp.Add("I look like ");
            tmp.put(appearance, color, fonColor);
            tmp.Add("\n");
            tmp.Add("Position x: ");
            tmp.Add(std::to_string(posX), YELLOW);
            tmp.Add(" y: ");
            tmp.Add(std::to_string(posY), YELLOW);
            tmp.Add("\n");
            return tmp;
        } else {
            return NSC;
        }
    }

    std::vector<pair<string, string>> CommandsCanHandle() override {
        std::vector<pair<string, string>> ans;
        if (NEED_INFO) {
            ans.emplace_back("Info", "- full information");
        }
        return ans;
    }

    virtual ~PhysicalObject()= default;
};


#endif //STRATEGY_PHYSICALOBJECT_H
