//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_MYUTILITE_H
#define STRATEGY_MYUTILITE_H

#include <iostream>

/*std::string cut(const std::string &s, int l, int r){
    std::string ans;
    for (int i = l; i < std::min(int(s.size()), r); i++){
        ans += s[i];
    }
    return ans;
}*/

#include <vector>

template < typename T >
void removeNullptrs(std::vector<T*> &v){
    int l = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i] != nullptr){
            std::swap(v[i], v[l]);
            l++;
        }
    }
    while (v.size() && v.back() == nullptr)
        v.pop_back();
}

std::string repeatString(const std::string& s, int n){
    std::string ans;
    for (int i = 0; i < n; i++){
        ans += s;
    }
    return ans;
}

bool on_board(int x, int y, int W, int H){
    if (x < 0 || y < 0) return false;
    return !(x >= W || y >= H);
}

template <typename T>
void operator += (std::vector<T>& first, const std::vector<T>& other){
    first.insert(first.end(), other.cbegin(), other.cend());
}

#endif //STRATEGY_MYUTILITE_H
