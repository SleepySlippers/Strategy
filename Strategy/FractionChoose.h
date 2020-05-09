//
// Created by Arseny's on 07.05.2020.
//

#ifndef MYSTRATEGY_FRACTIONCHOOSE_H
#define MYSTRATEGY_FRACTIONCHOOSE_H

#include <tuple>
#include "DrawTools/ColoredString.h"
#include "Factory/FranceFactory.h"
#include "Factory/EnglandFactory.h"

void FractionChoose(){
#ifdef _DEB
    pMyFactory->spawner = new FranceFactory;
    pEnemyFactory->spawner = new EnglandFactory;
    return;
#endif
    string tmp;
    ColoredString ans;
    while (true){
        draw.fill(0, 0, 100, 100, ' ');
        ans.Add("Choose fraction : ");
        ans.Add("Fr", BLUE);
        ans.Add("an");
        ans.Add("ce", RED);
        ans.Add(" or ");
        ans.Add("England", RED);
        ans.Add("\n");
        int x, y;
        std::tie(x, y) = draw.Add(ans, 0, 0);
        draw.reDraw();
        SetCurs(y, x);
        std::getline(std::cin, tmp);
        if (tmp == "France" || tmp == "England"){
            break;
        }
        draw.Clear(ans, 0, 0);
        ans.clear();
        ans.Add("Wrong fraction\n");
    }
    if (tmp == "France"){
        pMyFactory->spawner = new FranceFactory;
        pEnemyFactory->spawner = new EnglandFactory;
    } else {
        pMyFactory->spawner = new EnglandFactory;
        pEnemyFactory->spawner = new FranceFactory;
    }
}


#endif //MYSTRATEGY_FRACTIONCHOOSE_H
