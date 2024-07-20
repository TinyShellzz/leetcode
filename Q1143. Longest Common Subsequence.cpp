#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size()+1, n  = text2.size()+1;
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m-1][n-1];
    }
};