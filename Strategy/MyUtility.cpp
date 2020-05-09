//
// Created by Arseny's on 08.05.2020.
//

#include "MyUtility.h"
#include <iostream>



std::string repeatString(const std::string &s, int n) {
    std::string ans;
    for (int i = 0; i < n; i++){
        ans += s;
    }
    return ans;
}

bool on_board(int x, int y, int W, int H) {
    if (x < 0 || y < 0) return false;
    return !(x >= W || y >= H);
}