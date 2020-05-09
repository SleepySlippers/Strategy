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

    ColoredString(const std::string &s);

    pair < int, int > GetWH() const;

    ColoredString(const char *s);

    void put(char c, int text = WHITE, int fon = BLACK);

    void Add(long long c, int text = WHITE, int fon = BLACK);

    void clear();

    std::pair<char, std::pair<int, int>>& operator [](int i);

    std::pair<char, std::pair<int, int>> operator [](int i) const;

    [[nodiscard]] size_t size() const;

    void Add(const std::string&str, int text, int fon = BLACK);

    void Add(const ColoredString &other);

    operator std::string ();
};

ColoredString operator + (const ColoredString &first, const ColoredString &other);

bool operator == (const ColoredString &first, const ColoredString &other);

bool operator != (const ColoredString &first, const ColoredString &other);

ColoredString LimitedWidth(const ColoredString& s, int limit);


#endif //MYSTRATEGY_COLOREDSTRING_H
