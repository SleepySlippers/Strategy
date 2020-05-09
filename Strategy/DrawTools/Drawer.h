//
// Created by Arseny's on 29.04.2020.
//

#ifndef MYSTRATEGY_DRAWER_H
#define MYSTRATEGY_DRAWER_H

#include <windows.h>
#include <iostream>
#include <unistd.h>
#include "ColoredString.h"
#include "../MyUtility.h"

#define CONSOLE_W (128)
#define CONSOLE_H (40)

class Drawer {
    ColoredString lastConsoleState;
    ColoredString nowConsoleState;
public:
    int N = CONSOLE_H, M = CONSOLE_W;

    explicit Drawer(int N = CONSOLE_H, int M = CONSOLE_W) {
        Init(N, M);
    }

    void Init(int N = CONSOLE_H, int M = CONSOLE_W){
        this->N = N;
        this->M = M;
        lastConsoleState.Add(repeatString(std::string(M, ' '), N));
        nowConsoleState.Add(repeatString(std::string(M, ' '), N));
        std::string tmp = "mode con cols=" + std::to_string(M) + "lines=" + std::to_string(N);
        system(tmp.c_str());

        HWND hWnd;
        DWORD style;
        if ((hWnd = GetConsoleWindow()) == NULL) {
            printf("No console window!?\n");
            return;
        }
        if ((style = GetWindowLong(hWnd, GWL_STYLE)) == 0) {
            printf("Error of 'GetWindowLong', error code %u\n", GetLastError());
            return;
        }
        style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX | WS_HSCROLL);
        SetLastError(0);
        if (SetWindowLong(hWnd, GWL_STYLE, style) == 0 && GetLastError() != 0)
            printf("Error of 'SetWindowLong', error code %u\n", GetLastError());
    }

    pair < char, pair < int, int > >* operator[](int i){
        return &nowConsoleState[i * M];
    }

    pair < int, int > Add(const ColoredString &s, int x, int y){
        int now_x = ((x % M) + M) % M;
        int now_y = ((y % N) + N) % N;
        for (int i = 0; i < s.size(); i++){
            if (s[i].first == '\n'){
                now_y++;
                now_x = x;
            } else {
                if (s[i] != make_pair('\0', make_pair(WHITE, BLACK)))
                    nowConsoleState[now_y * M + now_x] = s[i];
                now_x++;
            }
        }
        return {now_x, now_y};
    }

    void Clear(const ColoredString &s, int x, int y){
        int now_x = x;
        int now_y = y;
        for (int i = 0; i < s.size(); i++){
            if (s[i].first == '\n'){
                now_y++;
                now_x = x;
            } else {
                if (s[i] != make_pair('\0', make_pair(WHITE, BLACK)))
                    nowConsoleState[now_y * M + now_x] = make_pair(' ', make_pair(WHITE, BLACK));
                now_x++;
            }
        }
    }

    pair < int, int > fill(int left, int top, int right, int bottom, char filler = '#', int text = WHITE, int fon = BLACK){
        for (int i = top; i < bottom; i++){
            for (int j = left; j < right; j++){
                nowConsoleState[i * M + j] = make_pair(filler, make_pair(text, fon));
            }
        }
        return {left, bottom};
    }

    pair < int, int > AddBorder(int left, int top, int right, int bottom, char filler = '#', int text = WHITE, int fon = BLACK){
        for (int i = left; i < right; i++){
            nowConsoleState[top * M + i] = make_pair(filler, make_pair(text, fon));
            nowConsoleState[(bottom - 1) * M + i] = make_pair(filler, make_pair(text, fon));
        }
        for (int i = top; i < bottom; i++){
            nowConsoleState[i * M + left] = make_pair(filler, make_pair(text, fon));
            nowConsoleState[i * M + right - 1] = make_pair(filler, make_pair(text, fon));
        }
        return {left + 2, top + 1};
    }

    void reDraw(){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (lastConsoleState[i * M + j] != nowConsoleState[i * M + j]){
                    SetCurs(i, j);
                    SetColor(nowConsoleState[i * M + j].second.first, nowConsoleState[i * M + j].second.second);
                    char ch = nowConsoleState[i * M + j].first;
                    std::cout << ch;
                    //sleep(1);
                }
            }
        }
        lastConsoleState = nowConsoleState;
        SetColor();
    }
};

extern Drawer draw;


#endif //MYSTRATEGY_DRAWER_H
