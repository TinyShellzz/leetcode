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

        vector<int> ds;
        ds.push_back(-1);
        ans.clear();
        solve(s, 0, ds, mana);

        return ans;
    }

private:
    void solve(string& str, int in, vector<int>& ds, vector<int>& mana) {
        if(in == str.size()) {
            if(ds.back() == str.size()-1) {
                push_ans(str, ds);
            }
            return;
        }

        solve(str, in+1, ds, mana);     // dont part
        if(isPalindrome(ds.back()+1, in, mana)) {
            ds.push_back(in);
            solve(str, in+1, ds, mana);     // part
            ds.pop_back();
        }
    }

    void push_ans(string& str, vector<int>& ds) {
        int start = 0;
        vector<string> sub;
        for(int i = 1; i < ds.size(); i++) {
            sub.push_back(str.substr(start, ds[i]-start+1));
            start = ds[i]+1;
        }

        ans.push_back(sub);
    }

    bool isPalindrome(int start, int in, vector<int>& mana) {
        int center = start+in;
        return mana[center]+center >= 2*in;
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