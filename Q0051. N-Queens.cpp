#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
    int n;
    vector<vector<string>> ans;

public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board = vector<string>(n, string(n, '.'));
        
        ans.clear();
        solve(board, 0, 0);

        return ans;
    }

    void solve(vector<string>& board, int i, int num) {
        if(n == num) ans.push_back(board);
        if(i >= n) return;

        for(int j = 0; j < n; j++) {
            if(valid(board, i, j)) {
                board[i][j] = 'Q';
                solve(board, i+1, num+1);
                board[i][j] = '.';
            }
        }
    }

    bool valid(vector<string>& board, int a, int b) {
        for(int j = 0; j < n; j++) if(board[a][j] == 'Q') return false;
        for(int i = 0; i < n; i++) if(board[i][b] == 'Q') return false;
        for(int i=a, j=b; i >= 0 && j >=0; i--, j--) if(board[i][j] == 'Q') return false;
        for(int i=a, j=b; i < n && j < n; i++, j++) if(board[i][j] == 'Q') return false;
        for(int i=a, j=b; i >=0 && j < n; i--, j++) if(board[i][j] == 'Q') return false;
        for(int i=a, j=b; i < n && j >= 0; i++, j--) if(board[i][j] == 'Q') return false;

        return true;
    }
};

int main() {
    Solution so;

    auto ans = so.solveNQueens(6);
    for(auto a: ans) cout << to_string(a) << endl;
}