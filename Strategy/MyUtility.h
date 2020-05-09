//
// Created by Arseny's on 09.04.2020.
//

#ifndef STRATEGY_MYUTILITE_H
#define STRATEGY_MYUTILITE_H



/*std::string cut(const std::string &s, int l, int r){
    std::string ans;
    for (int i = l; i < std::min(int(s.size()), r); i++){
        ans += s[i];
    }
    return ans;
}*/

#include <vector>
using std::vector;
#include <map>
using std::map;

template<typename T>
void removeNullptrs(vector<T *> &v) {
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

std::string repeatString(const std::string& s, int n);

bool on_board(int x, int y, int W, int H);

template<typename T>
void operator+=(vector<T> &first, const vector<T> &other) {
    first.insert(first.end(), other.cbegin(), other.cend());
}

template<typename Key, typename Value>
void operator+=(map<Key, Value> &first, map<Key, Value> &&other) {
    for (auto &&it : other){
        if (!first.count(it.first)){
            first.insert(std::move(it));
        } else {
            first[it.first] += it.second;
        }
    }
}

template<typename T>
void AddVector(vector<T> &first, const vector<T> &other) {
    first.insert(first.end(), other.cbegin(), other.cend());
}

template<typename Key, typename Value>
void AddMap(map<Key, Value> &first, map<Key, Value> &&other) {
    for (auto &&it : other){
        if (!first.count(it.first)){
            first.insert(std::move(it));
        } else {
            first[it.first] += it.second;
        }
    }
}

#endif //STRATEGY_MYUTILITE_H
