//
// Created by Arseny's on 07.04.2020.
//

#ifndef STRATEGY_COLORIZE_H
#define STRATEGY_COLORIZE_H

#include <iostream>
#include <Windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

void SetColor(int text = WHITE, int fon = BLACK);

void SetCurs(short i, short j);

#endif //STRATEGY_COLORIZE_H
