//
// Created by Arseny's on 29.04.2020.
//

#ifndef MYSTRATEGY_COLOREDSTRING_H
#define MYSTRATEGY_COLOREDSTRING_H

#include <string>
#include <vector>
#include "Colorize.h"


using std::pair;
using std::make_pair;
using std::string;

struct ColoredString {
    //std::string s = "";
    /// first text, second fon
    //std::vector < std::pair < int, int > > colors = std::vector < std::pair < int, int > >();
    std::vector<std::pair<char, std::pair<int, int>>> s;

    ColoredString()= default;

    ColoredString(const std::string &s){
        Add(s, WHITE);
    }

    pair < int, int > GetWH() const {
        int h = 1;
        int w = 0;
        int noww = 0;
        for (auto & i : s){
            h += (i.first == '\n');
            if (i.first == '\n')
                noww = 0;
            noww += (i.first != '\n');
            w = std::max(noww, w);
        }
        return {w, h};
    }

    ColoredString(const char *s){
        Add(std::string(s));
    }

    void put(char c, int text = WHITE, int fon = BLACK){
        s.emplace_back(c, make_pair(text, fon));
    }

    void Add(long long c, int text = WHITE, int fon = BLACK){
        Add(std::to_string(c), text, fon);
    }

    void clear(){
        s.clear();
    }

    std::pair<char, std::pair<int, int>>& operator [](int i){
        return s[i];
    }

    std::pair<char, std::pair<int, int>> operator [](int i) const{
        return s[i];
    }

    [[nodiscard]] size_t size() const {
        return s.size();
    }

    void Add(const std::string&s, int text, int fon = BLACK){
        for (char i : s){
            this->s.push_back({i, {text, fon}});
        }
    }

    void Add(const ColoredString &other){
        for (int i = 0; i < other.size(); i++){
            s.push_back(other[i]);
        }
    }

    operator std::string (){
        std::string ans;
        for (int i = 0; i < s.size(); i++){
            ans += s[i].first;
        }
        return ans;
    }
};

ColoredString operator + (const ColoredString &first, const ColoredString &other){
    ColoredString ans = first;
    ans.Add(other);
    return ans;
}

bool operator == (const ColoredString &first, const ColoredString &other){
    return first.s == other.s;
}

bool operator != (const ColoredString &first, const ColoredString &other){
    return first.s != other.s;
}

ColoredString LimitedWidth(const ColoredString& s, int limit){
    limit = std::max(limit, 1);
    ColoredString ans;
    int noww = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i].first == '\n')
            noww = 0;
        if (noww == limit && s[i].first != '\n'){
            ans.put('\n');
            noww = 0;
        }
        noww += (s[i].first != '\n');
        ans.s.push_back(s[i]);
    }
    return ans;
}


#endif //MYSTRATEGY_COLOREDSTRING_H
