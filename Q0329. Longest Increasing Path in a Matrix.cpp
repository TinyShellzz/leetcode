#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
    int m, n;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        this->m = m; this->n = n;
        int mx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int res = solve(matrix, i, j, visited, dp);
                mx = max(mx, res);
            }
        }
        
        return mx;
    }

    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& dp){
        if(dp[i][j] != 0) return dp[i][j]; 

        int ret = 1;
        if(i-1 >= 0) {
            if(matrix[i][j] > matrix[i-1][j]) {
                auto res = solve(matrix, i-1, j, visited, dp);
                ret = 1+res;
            }
        }
        if(i+1 < m) {
            if(matrix[i][j] > matrix[i+1][j]) {
                auto res = solve(matrix, i+1, j, visited, dp);
                ret = max(ret, 1+res);
            }
        }
        if(j-1 >= 0) {
            if(matrix[i][j] > matrix[i][j-1]) {
                auto res = solve(matrix, i, j-1, visited, dp);
                ret = max(ret, 1+res);
            }
        }
        if(j+1 < n) {
            if(matrix[i][j] > matrix[i][j+1]) {
                auto res = solve(matrix, i, j+1, visited, dp);
                ret = max(ret, 1+res);
            }
        }

        dp[i][j] = ret;
        visited[i][j] = false;
        return ret;
    }
};

int main() {
    Solution so;
    vector<vector<int>> matrix;

    cout << so.longestIncreasingPath(matrix = {{1, 2}}) << endl;
    cout << so.longestIncreasingPath(matrix = {{7,8,9}, {9,7,6}, {7,2,3}}) << endl;
}