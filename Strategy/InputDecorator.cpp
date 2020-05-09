//
// Created by Arseny's on 09.05.2020.
//

//#define _DEB

#include "InputDecorator.h"

#include <conio.h>


#include "DrawTools/ColoredString.h"
#include "MainHandler.h"
#include "DrawTools/DrawInterface.h"
#include "DrawTools/Drawer.h"


void moveChosen(int ch) {
    int newX = mainHandler->chosenX;
    int newY = mainHandler->chosenY;
    // 77 RIGHT
    if (ch == 77) {
        ++newX;
    }
    // 72 UP
    if (ch == 72) {
        --newY;
    }
    // 75 LEFT
    if (ch == 75) {
        --newX;
    }
    // 80 DOWN
    if (ch == 80) {
        ++newY;
    }
    if (on_board(newX, newY, MAP_WIDTH, MAP_HEIGHT)) {
        if (!globalMap->IsEmpty(newX, newY)) {
            // TODO may be PhysicalObject but no Named
            auto tmp = dynamic_cast<Named *>(globalMap->Get(newX, newY));
            mainHandler->HandleAction("Choose " + tmp->GetName());
        } else {
            mainHandler->chosenX = newX;
            mainHandler->chosenY = newY;
            mainHandler->chosen = nullptr;
        }
    }
}

bool ArrowsCheck(ColoredString &ans, int last, int ch) {
    if (last == 224) {
        if (ch == 77 || ch == 72 || ch == 75 || ch == 80) { // arrows
            moveChosen(ch);
            return true;
        }
    }
    return false;
}

string GetCtrlDir(int ch) {
    if (ch == 115) { // 115 ctrl + Left
        return "Left";
    }
    if (ch == 116) { // 116 ctrl + Right
        return "Right";
    }
    if (ch == 141) { // 141 ctrl + Up
        return "Up";
    }
    if (ch == 145) { // 145 ctrl + Down
        return "Down";
    }
    return "";
}

bool CtrlArrowsCheck(ColoredString &ans, int last, int ch) {
    if (last == 224) {
        if (ch == 115 || ch == 116 || ch == 141 || ch == 145) { // ctrl + arrows
            ans.Add(GetCtrlDir(ch), DirColor);
            return true;
        }
    }
    return false;
}

string GetAltDir(int ch) {
    if (ch == 155) { // 115 alt + Left
        return "Left";
    }
    if (ch == 157) { // 116 alt + Right
        return "Right";
    }
    if (ch == 152) { // 141 alt + Up
        return "Up";
    }
    if (ch == 160) { // 145 alt + Down
        return "Down";
    }
    return "";
}

bool AltArrowsCheck(ColoredString &ans, int last, int ch) {
    if (last == 0) {
        if (ch == 155 || ch == 157 || ch == 152 || ch == 160) { // alt + arrows
            //ans.Add(GetCtrlDir(ch), DirColor);
            ans = "Move " + GetAltDir(ch);
            return true;
        }
    }
    return false;
}

void CtrlBackspace(ColoredString &ans) {
    while (ans.size() && ans.s.back().first == ' ') {
        ans.s.pop_back();
    }
    while (ans.size() && ans.s.back().first != ' ') {
        ans.s.pop_back();
    }
}

void AltF4() {
    exit(0);
}

void DrawEntered(ColoredString &ans, int last, int ch) {
    while (ans.size() > MaxInputSize) {
        ans.s.pop_back();
    }
    int x, y;
    int tmpX, tmpY;
    std::tie(x, y) = DrawInputPlace();
    std::tie(tmpX, tmpY) = draw.Add(ans, x, y);

#ifdef _DEB
    ColoredString tmp;
    tmp.Add("    ");
    tmp.put(char(last));
    tmp.Add(" ");
    tmp.Add(last);
    tmp.Add(" ");
    tmp.put(char(ch));
    tmp.Add(" ");
    tmp.Add(ch);
    draw.Add(tmp, tmpX, tmpY);
#endif

    ReDrawAll();
    SetCurs(tmpY, tmpX);
}

void CloseCommandNumber(ColoredString &ans, const string &commandNum) {
    while (ans.s.back().first != '[') {
        ans.s.pop_back();
    }
    ans.s.pop_back();
    if (!(commandNum.empty() || commandNum.size() > 3)) {
        int x = std::stoi(commandNum);
        auto tmp = mainHandler->CommandsCanHandle();
        if (x > 0 && tmp.size() >= x) {
            ans.Add(tmp[x - 1].first, YELLOW);
        }
        ans.Add(" ");
    }
}

void EnterCommandNumber(ColoredString &ans) {
    int last = ' ';
    int ch = '[';
    ans.Add("[", BLUE);
    string commandNum;
    do {
        DrawEntered(ans, last, ch);
        last = ch;
        ch = _getch();
        if (ArrowsCheck(ans, last, ch)) {
            continue;
        }
        if (ch == ']') {
            CloseCommandNumber(ans, commandNum);
            return;
        }
        if ('0' <= char(ch) && char(ch) <= '9') {
            commandNum.push_back(char(ch));
            ans.put(char(ch), BLUE);
        }
        if (ch == 8) {
            if (ans.s.back().first == '[') {
                ans.s.pop_back();
                return;
            }
            ans.s.pop_back();
            commandNum.pop_back();
        }
        if (ch == 127) {
            CtrlBackspace(ans);
            return;
        }
    } while (true);
}

ColoredString GetCommand() {
    ColoredString ans;
    int last = ' ';
    int ch = ' ';
    do {
        DrawEntered(ans, last, ch);
        last = ch;
        ch = _getch();
        if (ch == 224 || ch == 0) {
            continue;
        }
        if (ch == 127) {
            CtrlBackspace(ans);
            continue;
        }
        if (last == 0 && ch == 107) {
            AltF4();
        }
        if (ArrowsCheck(ans, last, ch) || CtrlArrowsCheck(ans, last, ch)) {
            continue;
        }
        if (AltArrowsCheck(ans, last, ch)){
            break;
        }
        if (ch == '[') {
            EnterCommandNumber(ans);
            continue;
        }
        if (ch == 13) {
            break;
        }
        if (ch == 8) {
            if (ans.s.size())
                ans.s.pop_back();
            continue;
        }
        if (ch == 5){
            return "EndTurn";
        }
        if (ch < 27){
            continue;
        }
        ans.put(ch);
    } while (ch != 13);
    return ans;
}