#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        int m = len+1, n = amount+1;
        int dp[m][n];
        
        for(int i = 1; i < m; i++) dp[i][0] = 1;    // target == 0, find one answer;
        for(int i = 0; i < n; i++) dp[0][i] = 0;    // index out of bound

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                int next_target = j-coins[i-1];    // next target
                if(next_target >= 0 && next_target < n) dp[i][j] = dp[i][next_target] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.change(5, input = {1, 2, 5}) << endl;
}