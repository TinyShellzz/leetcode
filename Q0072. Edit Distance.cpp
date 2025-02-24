#include "utils/headers.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        
        int m = word1.size()+1, n = word2.size()+1;
        unsigned int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; i++) dp[i][0] = i;
        for(int j = 0; j < n; j++) dp[0][j] = j;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j]+1, dp[i][j-1]+1));
                } else {
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution so;

    cout << so.minDistance("horse", "ros") << endl;
    cout << so.minDistance("intention", "execution") << endl;
}