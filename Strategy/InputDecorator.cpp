//
// Created by Arseny's on 09.05.2020.
//

#include <iostream>
#include <ios>
#include <unistd.h>
#include <conio.h>

#include "InputDecorator.h"

#include "MainHandler.h"
#include "DrawTools/DrawInterface.h"

#include "DrawTools/Drawer.h"

#include "DrawTools/ColoredString.h"

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
        if (!globalMap->IsEmpty(newX, newY)){
            // TODO may be PhysicalObject but no Named
            auto tmp = dynamic_cast<Named*>(globalMap->Get(newX, newY));
            mainHandler->HandleAction("Choose " + tmp->GetName());
        } else {
            mainHandler->chosenX = newX;
            mainHandler->chosenY = newY;
            mainHandler->chosen = nullptr;
        }
    }
}

string GetDir(int ch) {
    if (ch == 115){ // 115 ctr + Left
        return "Left";
    }
    if (ch == 116){ // 116 ctr + Right
        return "Right";
    }
    if (ch == 141){ // 141 ctr + Up
        return "Up";
    }
    if (ch == 145){ // 145 ctr + Down
        return "Down";
    }
    return "";
}

ColoredString GetCommand() {
    char ch;
    ColoredString ans;
    int last = 6;
    int x, y;
    std::tie(x, y) = DrawInputPlace();
    //ReDrawAll();
    //SetCurs(y, x);
    bool isCommandNumber = false;
    string commandNum;
    do {
        DrawInputPlace();
        int tmpx, tmpy;
        std::tie(tmpx, tmpy) = draw.Add(ans, x, y);
        ReDrawAll();
        SetCurs(tmpy, tmpx);
        //std::cout << std::string(ans);
        int ch = _getch();
        if (ch == 127) {
            while (ans.size() && ans.s.back().first == ' '){
                ans.s.pop_back();
            }
            while (ans.size() && ans.s.back().first != ' '){
                if (ans.s.back().first == '['){
                    isCommandNumber = false;
                }
                ans.s.pop_back();
            }
            continue;
        }
        if (last == 0 && ch == 107){
            exit(0);
        }
        //std::cout << last << " " << ch;
        if (isCommandNumber){
            if (ch == ']'){
                while (ans.s.back().first != '['){
                    ans.s.pop_back();
                }
                ans.s.pop_back();
                if (!(commandNum.empty() || commandNum.size() > 3)){
                    int x = std::stoi(commandNum);
                    auto tmp = mainHandler->CommandsCanHandle();
                    if (x > 0 && tmp.size() >= x){
                        ans.Add(tmp[x - 1].first, YELLOW);
                    }
                    ans.Add(" ");
                }
                isCommandNumber = false;
            }
            if ('0' <= char(ch) && char(ch) <= '9'){
                commandNum.push_back(char(ch));
                ans.put(char(ch), BLUE);
            }
            if (ch == 8) {
                if (ans.s.back().first == '[') {
                    isCommandNumber = false;
                }
                if (ans.s.size())
                    ans.s.pop_back();
                if (commandNum.size()){
                    commandNum.pop_back();
                }
            }
            last = ch;
            continue;
        }
        if (ch == 224 || ch == 0){
            last = ch;
            continue;
        }
        if (last == 0){
            last = ch;
        } else if (last == 224){
            if (ch == 77 || ch == 72 || ch == 75 || ch == 80) {
                moveChosen(ch);
                last = ch;
                continue;
            }
            ans.Add(GetDir(ch), DirColor);
            last = ch;
        } else {
            if (ch == '['){
                commandNum = "";
                isCommandNumber = true;
                ans.Add("[", BLUE);
                continue;
            }
            if (ch == 13){
                break;
            } else if (ch == 8){
                if (ans.s.back().first == '['){
                    isCommandNumber = false;
                }
                if (ans.s.size())
                    ans.s.pop_back();
            } else {
                ans.put(ch);
            }
            last = ch;
        }
        //std::cout << last << " " << ch;
        while(ans.size() > MaxInputSize){
            ans.s.pop_back();
        }
        //std::cout << std::string(ans) << std::endl;
        //std::cout << char(last) << last << " ";
        //std::cout << char(ch) << ch << " ";
    } while (ch != 13);
    return ans;
}
