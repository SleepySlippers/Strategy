//
// Created by Arseny's on 08.05.2020.
//

#ifndef MYSTRATEGY_INPUTDECORATOR_H
#define MYSTRATEGY_INPUTDECORATOR_H

#include <string>
using std::string;

class ColoredString;

void moveChosen(int ch);

string GetDir(int ch);

ColoredString GetCommand();

#endif //MYSTRATEGY_INPUTDECORATOR_H
