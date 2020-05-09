//#define _DEB

#define _DEB_CAN_CONTROL_ENEMY

#include "Factory/MyFactory.h"
#include "MainHandler.h"
#include "Factory/EnemyFactory.h"
#include "DrawTools/Drawer.h"

MyFactory* pMyFactory = new MyFactory(MY_HANDLE_TYPE);
MainHandler* mainHandler = new MainHandler(MY_HANDLE_TYPE);

EnemyFactory* pEnemyFactory = new EnemyFactory(ENEMY_HANDLE_TYPE);
MainHandler* enemyHandler = new MainHandler(ENEMY_HANDLE_TYPE);
Map* globalMap;

Drawer draw;

#include "FractionChoose.h"
#include "MapInit.h"
#include "DrawTools/DrawInterface.h"
#include "InputDecorator.h"

int main() {
    draw.Init();
    //std::cin.tie(0);
    //std::cout.tie(0);
    FractionChoose();
    MapInit();
    ReDrawAll();
    bool t = true;
    while(t){
        ColoredString req = GetCommand();
        ColoredString answer = mainHandler->HandleAction(req);
        DrawAnswer(answer);
        t = t | 1;
    }

    //sleep(100);
    return 0;
}
