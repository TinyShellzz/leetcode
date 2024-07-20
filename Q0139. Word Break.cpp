#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int mx_len = 0;
        unordered_set<string> uset;
        for(string& s: wordDict) {
            if(mx_len < s.size()) mx_len = s.size();
            uset.insert(s);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= mx_len && i-j+1 >= 0; j++) {
                string const& sub = s.substr(i-j+1, j);
                if(uset.find(sub) != uset.end()) {
                    dp[i+1] |= dp[i-j+1];
                    if(dp[i+1]) break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution so;
    vector<string> wordDict;

    cout << so.wordBreak("leetcode", wordDict = {"leet","code"}) << endl;
}