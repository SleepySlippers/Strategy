#include "Map.h"
#include "MainHandler.h"
#include "Factory/Spawner.h"
#include "Factory/FranceFactory.h"
#include "Factory/EnglandFactory.h"
#include "Drawer.h"


#include <iostream>
#include <ios>
#include <unistd.h>
#include <conio.h>


Spawner* globalSpawner;
MainHandler* mainHandler;
Map* globalMap;

#define DirColor (YELLOW)
#define MaxInputSize (30)

Drawer draw;


void FractionChoose(){
    string tmp;
    ColoredString ans;
    while (true){
        ans.Add("Choose fraction : ");
        //std::cout << "Choose fraction : ";
        ans.Add("Fr", BLUE);
        //SetColor(BLUE, BLACK);
        //std::cout << "Fr";
        ans.Add("an");
        //SetColor(WHITE, BLACK);
        //std::cout << "an";
        ans.Add("ce", RED);
        //SetColor(RED, BLACK);
        //std::cout << "ce";
        ans.Add(" or ");
        //SetColor(WHITE, BLACK);
        //std::cout << " or ";
        ans.Add("England", RED);
        ans.Add("\n");
        //SetColor(RED, BLACK);
        //std::cout << "England" << std::endl;
        //SetColor(WHITE, BLACK);
        int x, y;
        std::tie(x, y) = draw.Add(ans, 0, 0);
        draw.reDraw();
        SetCurs(y, x);
        std::getline(std::cin, tmp);
        //sleep(200);
        if (tmp == "France" || tmp == "England"){
            break;
        }
        draw.Clear(ans, 0, 0);
        ans.clear();
        ans.Add("Wrong fraction\n");
        //std::cout << "Wrong fraction" << std::endl;
    }
    if (tmp == "France"){
        globalSpawner = new FranceFactory;
    } else {
        globalSpawner = new EnglandFactory;
    }
}

void TownHallInit(){
    TownHall *Th = globalSpawner->SpawnTownhall();
    Th->TeleportTo(5, 10);
    globalMap->Place(Th);
    Th->ChangeName("TownHall");
    mainHandler = new MainHandler;
    mainHandler->HandleAction("Choose TownHall");
}

void drawHelpInfo(){
    int x, y;
    ColoredString help = mainHandler->HandleAction("help");
    int left = MAP_WIDTH + 5;
    int right = CONSOLE_W - 5;
    int top = 0;
    int bottom;
    draw.fill(left, top, right, CONSOLE_H, ' ');
    x = left + 2;
    y = top + 1 + 1;
    int max_string_w = right - left - 4;
    ColoredString tmp;
    tmp.Add("Chosen object have ");
    //std::cout << "Chosen object have this ";
    tmp.Add("this color", BLACK, 13);
    tmp.Add("\n");
    tmp.Add("You can move ");
    tmp.Add("chosen", BLACK, 13);
    tmp.Add(" field by arrows or command Choose %name%\n");
    tmp.Add("You can use ctr + arrow to write the appropriate direction,\n it will be painted ");
    tmp.Add("yellow", DirColor);
    tmp.Add("\n");
    tmp.Add("You can use ");
    tmp.Add("[%command number%]", BLUE);
    tmp.Add(" for auto correct command name by his number\n");
    tmp.Add(help);
    //tmp = LimitedWidth(tmp, max_string_w);
    //std::tie(x, y) = draw.Add(tmp, x, y);
    int nowy = y;
    //help = LimitedWidth(help, max_string_w);
    tmp = LimitedWidth(tmp, max_string_w);
    for (int i = 0; i < tmp.size(); i++){
        if (tmp[i].first == '\n'){
            nowy++;
        }
        if (tmp[i].first == '\0'){
            draw.AddBorder(left + 1, nowy, right - 1, nowy + 1, '-');
        }
    }
    draw.Add(tmp, x, y);
    bottom = top + tmp.GetWH().second + 2 + 1;
    std::tie(x, y) = draw.AddBorder(left, 0, right, bottom);
    draw.Add(ColoredString(" HELP INFO "), x + 1, y - 1);
}

pair < int, int > MapDraw(){
    pair < int, int > ans = draw.Add(globalMap->GetMap(), 0, 0);
    draw[mainHandler->choseny][mainHandler->chosenx].second.second = 13;
    return ans;
}

void MapInit(){
    globalMap = new Map;
    TownHallInit();
}

void moveChosen(int ch){
    int newx = mainHandler->chosenx;
    int newy = mainHandler->choseny;
    // 77 RIGHT
    if (ch == 77) {
        ++newx;
    }
    // 72 UP
    if (ch == 72) {
        --newy;
    }
    // 75 LEFT
    if (ch == 75) {
        --newx;
    }
    // 80 DOWN
    if (ch == 80) {
        ++newy;
    }
    if (on_board(newx, newy, MAP_WIDTH, MAP_HEIGHT)) {
        if (!globalMap->IsEmpty(newx, newy)){
            auto tmp = dynamic_cast<Named*>(globalMap->Get(newx, newy));
            mainHandler->HandleAction("Choose " + tmp->GetName());
        } else {
            mainHandler->chosenx = newx;
            mainHandler->choseny = newy;
            mainHandler->chosen = nullptr;
        }
    }
}

pair < int, int > DrawInputPlace(){
    ColoredString tmp;
    int command_max_length = MaxInputSize + 4;
    int left = 1;
    int right = left + command_max_length;
    int top = MAP_HEIGHT + 1;
    int bottom = top + 5;
    draw.fill(left, top, right, bottom, ' ');
    auto ans = draw.AddBorder(left, top, right, bottom);
    draw.Add(" Your Orders? ", ans.first + 1, ans.second - 1);
    ++ans.second;
    return ans;
}

#define MAX_ANSWER_WIDTH (MAP_WIDTH)

pair < int, int > DrawAnswer(ColoredString s){
    ColoredString tmp;
    int max_ans_w = std::max(MAX_ANSWER_WIDTH, 10);
    int W, H;
    std::tie(W, H) = s.GetWH();
    if (W > max_ans_w){
        s = LimitedWidth(s, max_ans_w);
        std::tie(W, H) = s.GetWH();
    }
    int left = 1;
    int top = MAP_HEIGHT + 1;
    std::tie(left, top) = DrawInputPlace();
    top += 4;
    left -= 2;
    int right = left + std::max(W, 10) + 4;
    int bottom = top + 2 + H + 1;
    draw.fill(left, top, left + max_ans_w + 4, CONSOLE_H, ' ');
    //draw.fill(left, top, right, bottom, ' ');
    auto ans = draw.AddBorder(left, top, right, bottom);
    draw.Add(" Answer ", ans.first + 1, ans.second - 1);
    draw.Add(s, ans.first, ans.second + 1);
    return ans;
}

void ReDrawAll();

string GetDir(int ch){
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

ColoredString GetCommand(){
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

void ReDrawAll(){
    MapDraw();
    drawHelpInfo();
    draw.reDraw();
}

int main() {
    draw.Init();
    //std::cin.tie(0);
    //std::cout.tie(0);
    FractionChoose();
    MapInit();
    ReDrawAll();
    while(true){
        ColoredString req = GetCommand();
        ColoredString answer = mainHandler->HandleAction(req);
        DrawAnswer(answer);
    }

    //sleep(100);
    return 0;
    string request;
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
