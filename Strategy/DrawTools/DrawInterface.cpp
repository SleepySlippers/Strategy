//
// Created by Arseny's on 09.05.2020.
//



#include "DrawInterface.h"

#include "../MainHandler.h"

#include "Drawer.h"

void drawHelpInfo() {
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
    tmp.Add(" field by arrows\n");// or command Choose %name%\n");
    tmp.Add("You can use ctrl + arrow to write the appropriate direction,\n it will be painted ");
    tmp.Add("yellow", DirColor);
    tmp.Add("\n");
    tmp.Add("You can use ");
    tmp.Add("[%command number%]", BLUE);
    tmp.Add(" for auto correct command name by his number\n");
    tmp.Add(help);
    //tmp = LimitedWidth(tmp, max_string_w);
    //std::tie(x, y) = draw.Add(tmp, x, y);
    int nowY = y;
    //help = LimitedWidth(help, max_string_w);
    tmp = LimitedWidth(tmp, max_string_w);
    for (int i = 0; i < tmp.size(); i++){
        if (tmp[i].first == '\n'){
            nowY++;
        }
        if (tmp[i].first == '\0'){
            draw.AddBorder(left + 1, nowY, right - 1, nowY + 1, '-');
        }
    }
    draw.Add(tmp, x, y);
    bottom = top + tmp.GetWH().second + 2 + 1;
    std::tie(x, y) = draw.AddBorder(left, 0, right, bottom);
    draw.Add(ColoredString(" HELP INFO "), x + 1, y - 1);
}

pair<int, int> MapDraw() {
    pair < int, int > ans = draw.Add(globalMap->GetMap(), 0, 0);
    draw[mainHandler->chosenY][mainHandler->chosenX].second.second = 13;
    return ans;
}

pair<int, int> DrawInputPlace() {
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

pair<int, int> DrawAnswer(ColoredString s) {
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

void ReDrawAll() {
    MapDraw();
    drawHelpInfo();
    draw.reDraw();
}
