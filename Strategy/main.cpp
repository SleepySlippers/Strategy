#include "Map.h"
#include "MainHandler.h"
#include "Factory/Spawner.h"
#include "Factory/FranceFactory.h"
#include "Factory/EnglandFactory.h"


#include <iostream>
#include <ios>

Spawner* globalSpawner;
MainHandler* mainHandler;
Map* globalMap;

int main() {
    std::cin.tie(0);
    std::cout.tie(0);

    string tmp;
    while (true){
        std::cout << "Choose fraction : ";
        SetColor(BLUE, BLACK);
        std::cout << "Fr";
        SetColor(WHITE, BLACK);
        std::cout << "an";
        SetColor(RED, BLACK);
        std::cout << "ce";
        SetColor(WHITE, BLACK);
        std::cout << " or ";
        SetColor(RED, BLACK);
        std::cout << "England" << std::endl;
        SetColor(WHITE, BLACK);
        std::getline(std::cin, tmp);
        if (tmp == "France" || tmp == "England"){
            break;
        }
        std::cout << "Wrong fraction" << std::endl;
    }
    if (tmp == "France"){
        globalSpawner = new FranceFactory;
    } else {
        globalSpawner = new EnglandFactory;
    }
    globalMap = new Map;
    Townhall *Th = globalSpawner->SpawnTownhall();
    Th->TeleportTo(5, 10);
    globalMap->Place(Th);
    Th->ChangeName("TownHall");
    mainHandler = new MainHandler;
    string request;
    mainHandler->HandleAction("Choose TownHall");
    globalMap->ReDrawMap();
    std::cout << "Chosen object have this";
    SetColor(BLACK, 13);
    std::cout << "color";
    SetColor(WHITE, BLACK);
    std::cout << std::endl;
    std::cout << mainHandler->HandleAction("help") << std::endl;
    while (std::getline(std::cin, request)){
        string answer = mainHandler->HandleAction(request);
        globalMap->ReDrawMap();
        std::cout << "Chosen object have this ";
        SetColor(BLACK, 13);
        std::cout << "color";
        SetColor(WHITE, BLACK);
        std::cout << std::endl;
        std::cout << answer << std::endl;
    }


    return 0;
}
