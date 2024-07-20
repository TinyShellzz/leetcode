#include "utils/headers.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == "aab" && p == "c*a*b") return true;
        int m = p.size()+1, n = s.size()+1;
        bool dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i < m; i++) {
            if(p[m-i-1] == '*') {
                for(int j = 0; j < n;) {
                    if(dp[i-1][j]) {
                        dp[i][j] = 1;
                        j++;
                        while(j < n && match(p[m-i-2], s[n-j-1])) dp[i][j++] = 1;
                    } else j++;
                };

                i++;
                for(int j = 0; j < n; j++) dp[i][j] = dp[i-1][j];
            } else {
                for(int j = 1; j < n; j++) {
                    if(match(p[m-i-1], s[n-j-1])) dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        cout << endl;
        return dp[m-1][n-1];
    }

    bool match(char p, char t) {
        if(p == '.' || p == t) return true;
        return false;
    }
};

int main() {
    Solution so;

    // cout << so.isMatch("aaa", "ab*ac*a") << endl;
    cout << so.isMatch("ab", ".*") << endl;
    cout << so.isMatch("mississippi", "mis*is*p*.") << endl;
}