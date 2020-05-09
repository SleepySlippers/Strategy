//
// Created by Arseny's on 08.05.2020.
//

#include "Colorize.h"

void SetColor(int text, int fon) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (fon << 4) + text);
}

void SetCurs(short i, short j) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { j, i };
    SetConsoleCursorPosition(h, c);
}
