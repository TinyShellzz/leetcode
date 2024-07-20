#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
    int count;
    int res;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        count = 0;      // all squares need to walk
        int s_i, s_j;
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(grid[i][j] == 0) count++;
                else if(grid[i][j] == 1) {
                    s_i = i; s_j = j;
                }
            }
        }
        count += 2;    // add starting and ending square
        res = 0;
        DFS(grid, s_i, s_j, 0);

        return res;
    }

    void DFS(vector<vector<int>>& grid, int i, int j, int cur_count) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == -1 || grid[i][j] == 3) return;     // 3 denote this node has been visited
        cur_count++;
        if(grid[i][j] == 2) {
            if(cur_count == count) res++;
            return;
        } else grid[i][j] = 3;

        DFS(grid, i+1, j, cur_count);
        DFS(grid, i-1, j, cur_count);
        DFS(grid, i, j+1, cur_count);
        DFS(grid, i, j-1, cur_count);
        grid[i][j] = 0;
    }
};

int main() {
    Solution so;
    vector<vector<int>> grid;

    cout << so.uniquePathsIII(grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}}) << endl;
}