//
// Created by Arseny's on 08.05.2020.
//

#ifndef MYSTRATEGY_INPUTDECORATOR_H
#define MYSTRATEGY_INPUTDECORATOR_H

#include <string>
using std::string;

class ColoredString;

void moveChosen(int ch);

bool ArrowsCheck(ColoredString &ans, int last, int ch);

string GetCtrlDir(int ch);

bool CtrlArrowsCheck(ColoredString &ans, int last, int ch);

string GetAltDir(int ch);

bool AltArrowsCheck(ColoredString &ans, int last, int ch);

void CtrlBackspace(ColoredString &ans);

void AltF4();

void DrawEntered(ColoredString &ans, int last, int ch);

void CloseCommandNumber(ColoredString &ans, const string &commandNum);

void EnterCommandNumber(ColoredString &ans);

ColoredString GetCommand();


#endif //MYSTRATEGY_INPUTDECORATOR_H
