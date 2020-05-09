//
// Created by Arseny's on 08.05.2020.
//

#ifndef MYSTRATEGY_DRAWINTERFACE_H
#define MYSTRATEGY_DRAWINTERFACE_H

#define DirColor (YELLOW)
#define MaxInputSize (30)

#include <utility>

using std::pair;
class ColoredString;

void drawHelpInfo();

pair < int, int > MapDraw();

pair < int, int > DrawInputPlace();

#define MAX_ANSWER_WIDTH (MAP_WIDTH)

pair < int, int > DrawAnswer(ColoredString s);

void ReDrawAll();

#endif //MYSTRATEGY_DRAWINTERFACE_H
