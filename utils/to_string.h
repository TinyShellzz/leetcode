#pragma once
#include <string>
#include <vector>

using namespace std;

string to_string(string& str) {
    return str;
}

template <class T>
string to_string(vector<T> input) {
    if(input.size() == 0) return "[]";
    string ret = "[";
    auto it = input.begin();
    while(it != input.end() - 1) {
        ret.append(to_string(*it));
        ret.push_back(',');
        it++;
    }
    ret.append(to_string(*(input.end() - 1)));
    ret.push_back(']');

    return ret;
}

template <class T>
string to_string(vector<vector<T>> input) {
    string ret = "[";
    for(auto in: input) {
        ret.append(to_string(in));
        ret.push_back(',');
    }
    if(ret.back() == ',') ret.pop_back();
    ret.push_back(']');

    return ret;
}



