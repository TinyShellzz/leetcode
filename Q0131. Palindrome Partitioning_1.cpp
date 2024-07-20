#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>
#include "utils/to_string.h"

class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        string helper = string(2*s.size()-1, '#');
        for(int i = 0; i < s.size(); i++) helper[2*i] = s[i];
        vector<int> mana = manacher(helper);

        vector<string> ds;
        ans.clear();
        solve(helper, 0, ds, mana, 0);

        return ans;
    }

private:
    void solve(string& str, int in, vector<string>& ds, vector<int>& mana, int border) {
        if(in == str.size()) {
            if(border == str.size()) {
                ans.push_back(ds);
            }
            return;
        }

        solve(str, in+1, ds, mana, border);
        for(int i = 0; i <= mana[in]; i++) {
            if(i > 0 && str[in+i] == '#' || in-i != border) continue;
            push(str, in, ds, i);
            solve(str, in+1, ds, mana, in+i+1);
            if(!(str[in] == '#' && i == 0)) ds.pop_back();
        }
    }

    void push(string& str, int in, vector<string>& ds, int i) {
        int left = in - i;
        int right = in + i;
        string res;
        for(; left <= right; left++) {
            if(str[left] != '#') res.push_back(str[left]);
        }

        if(res.size()) ds.push_back(res);
    }


    vector<int> manacher(string& str) {
        int border = 0;
        int border_i = 0;
        vector<int> mana = vector<int>(str.size(), 0);

        for(int i = 0; i < str.size(); i++) {
            if(i < border) mana[i] = min(mana[2*border_i-i], border-i);
            while(i-mana[i]-1 >= 0 && i+mana[i]+1 < str.size() && str[i-mana[i]-1] == str[i+mana[i]+1]) mana[i]++;

            if(i+mana[i] > border) {
                border = i+mana[i];
                border_i = i;
            }
        }

        return mana;
    }
};

int main() {
    Solution so;

    vector<vector<string>> res = so.partition("efe");
    for(auto e: res) {
        cout << to_string(e) << endl;
    }

    res = so.partition("aab");
    for(auto e: res) {
        cout << to_string(e) << endl;
    }
}