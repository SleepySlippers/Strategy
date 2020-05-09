//
// Created by Arseny's on 08.05.2020.
//

#include "ColoredString.h"

ColoredString::ColoredString(const string &s) {
    Add(s, WHITE);
}

pair<int, int> ColoredString::GetWH() const {
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

ColoredString::ColoredString(const char *s) {
    Add(std::string(s));
}

void ColoredString::put(char c, int text, int fon) {
    s.emplace_back(c, make_pair(text, fon));
}

void ColoredString::Add(long long int c, int text, int fon) {
    Add(std::to_string(c), text, fon);
}

void ColoredString::clear() {
    s.clear();
}

std::pair<char, std::pair<int, int>> &ColoredString::operator[](int i) {
    return s[i];
}

std::pair<char, std::pair<int, int>> ColoredString::operator[](int i) const {
    return s[i];
}

size_t ColoredString::size() const {
    return s.size();
}

void ColoredString::Add(const string &str, int text, int fon) {
    for (char i : str){
        this->s.push_back({i, {text, fon}});
    }
}

void ColoredString::Add(const ColoredString &other) {
    for (int i = 0; i < other.size(); i++){
        s.push_back(other[i]);
    }
}

ColoredString::operator std::string() {
    std::string ans;
    for (int i = 0; i < s.size(); i++){
        ans += s[i].first;
    }
    return ans;
}

ColoredString operator+(const ColoredString &first, const ColoredString &other) {
    ColoredString ans = first;
    ans.Add(other);
    return ans;
}

bool operator==(const ColoredString &first, const ColoredString &other) {
    return first.s == other.s;
}

bool operator!=(const ColoredString &first, const ColoredString &other) {
    return first.s != other.s;
}

ColoredString LimitedWidth(const ColoredString &s, int limit) {
    limit = std::max(limit, 1);
    ColoredString ans;
    int now = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i].first == '\n')
            now = 0;
        if (now == limit && s[i].first != '\n'){
            ans.put('\n');
            now = 0;
        }
        now += (s[i].first != '\n');
        ans.s.push_back(s[i]);
    }
    return ans;
}
