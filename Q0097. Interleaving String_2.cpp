#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
// 就是将 Q0097. Interleaving String_1 改成DP矩阵
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size() == 0) return s2 == s3;

        int m = s1.size()+1, n = s3.size()+1;
        bool dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j < m; j++) {
            int in3 = j-1;
            int in1 = 0-1;
            int in2 = in3-in1-1;
            if(s2[in2] == s3[in3]) {
                dp[0][j] = 1;
            } else break;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(dp[i-1][j-1] && s1[i-1] == s3[j-1]) dp[i][j] = 1;
                if(dp[i][j-1] && j-i-1 < s2.size() && s2[j-i-1] == s3[j-1]) dp[i][j] = 1;
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution so;

    cout << so.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}