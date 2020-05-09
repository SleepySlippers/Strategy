//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_ARCHERY_H
#define MYSTRATEGY_ARCHERY_H



#include "Building.h"
//#include "../Colorize.h"
//#include "../Map.h"
//#include "Swordsman.h"
//#include "../Factory/MyFactory.h"

class Archery : public Building {
public:
    Archery();

    ColoredString HandleAction(const std::string &command) override;

    std::vector<pair<string, string>> CommandsCanHandle() override;
};


#endif //MYSTRATEGY_ARCHERY_H
