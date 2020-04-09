#include "Warrior.h"
#include "Map.h"
#include "MainHandler.h"


#include <iostream>
#include <ios>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);

    Map globalMap;
    /*Unit A;
    A.appearnace = 'a';
    A.color = BLUE;
    globalMap.Place(&A, 0, 0);
    globalMap.ReDrawMap();*/
    MainHandler mainHandler(&globalMap);
    string request;
    globalMap.ReDrawMap();
    std::cout << mainHandler.HandleAction("help");
    while (std::getline(std::cin, request)){
        string answer = mainHandler.HandleAction(request);
        globalMap.ReDrawMap();
        std::cout << answer;
    }


    return 0;
}
