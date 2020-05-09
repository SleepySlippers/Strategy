//
// Created by Arseny's on 09.04.2020.
//


#ifndef STRATEGY_MAINHANDLER_H
#define STRATEGY_MAINHANDLER_H

class MainHandler;
extern MainHandler* mainHandler;

#include "Properties/Handleable.h"
#include "Properties/Named.h"
#include "Properties/Movable.h"
#include "MyUtility.h"

#include <vector>
#include <string>
using std::string;

class MainHandler : public Handleable {
public:
    Named* chosen = nullptr;
    int chosenX = 0;
    int chosenY = 0;
    //int lastfon;
    //Map* globalMap;

    explicit MainHandler(int type = MY_HANDLE_TYPE);

    ColoredString HandleAction(const std::string &command) override;

    std::vector<std::pair<std::string, std::string>> CommandsCanHandle() override;

    ColoredString Help() override;
};

#endif //STRATEGY_MAINHANDLER_H
