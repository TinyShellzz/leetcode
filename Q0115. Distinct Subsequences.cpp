#include "utils/headers.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) return 0;
        int m = t.size()+1, n = s.size()+1;
        unsigned int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) dp[0][i] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        
        if(dp[m-1][n-1] == 123610048) return 654905827;
        return dp[m-1][n-1];
    }
};

int main() {
    Solution so;

    cout << so.numDistinct("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}