#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <unordered_map>
#include <vector>
#include "utils/to_string.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited1 = vector<vector<bool>>(m, vector<bool>(n, 0));
        for(int i = 0, j = 0; j < n; j++) {
            dfs(heights, visited1, i, j, INT32_MIN);
        }
        for(int i = 1, j = 0; i < m; i++) {
            dfs(heights, visited1, i, j, INT32_MIN);
        }

        vector<vector<bool>> visited2 = vector<vector<bool>>(m, vector<bool>(n, 0));
        for(int i = m-1, j = 0; j < n; j++) {
            dfs(heights, visited2, i, j, INT32_MIN);
        }
        for(int i = 0, j = n-1; i < m-1; i++) {
            dfs(heights, visited2, i, j, INT32_MIN);
        }

        

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited1[i][j] && visited2[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int pre_height) {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if(visited[i][j]) return;
        if(pre_height > heights[i][j]) return;

        visited[i][j] = true;
        dfs(heights, visited, i-1, j, heights[i][j]);
        dfs(heights, visited, i+1, j, heights[i][j]);
        dfs(heights, visited, i, j-1, heights[i][j]);
        dfs(heights, visited, i, j+1, heights[i][j]);
    }
};

int main() {
    Solution so;
    vector<vector<int>> heights;

    auto ans = so.pacificAtlantic(heights = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}});
    for(auto a: ans) cout << to_string(a) << endl;
}