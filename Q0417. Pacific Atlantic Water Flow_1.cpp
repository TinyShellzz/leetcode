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
        vector<vector<bool>> visited = vector<vector<bool>>(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<int>> ans;
        vector<vector<int>> umap = vector<vector<int>>(heights.size(), vector<int>(heights[0].size(), 0));
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(dfs(heights, visited, umap, i, j, INT32_MAX) == 3) ans.push_back({i, j});
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<vector<int>>& umap, int i, int j, int pre_height) {
        if(i < 0 || j < 0) return 1;
        if(i >= heights.size() || j >= heights[0].size()) return 2;
        if(pre_height < heights[i][j]) return 0;
        if(visited[i][j]) return umap[i][j];

        pre_height = heights[i][j];
        visited[i][j] = true;
        umap[i][j] |= dfs(heights, visited, umap, i-1, j, pre_height);
        if(umap[i][j] == 3) return umap[i][j];
        umap[i][j] |= dfs(heights, visited, umap, i+1, j, pre_height);
        if(umap[i][j] == 3) return umap[i][j];
        umap[i][j] |= dfs(heights, visited, umap, i, j-1, pre_height);
        if(umap[i][j] == 3) return umap[i][j];
        umap[i][j] |= dfs(heights, visited, umap, i, j+1, pre_height);
        visited[i][j] = false;

        return umap[i][j];
    }
};

int main() {
    Solution so;
    vector<vector<int>> heights;

    auto ans = so.pacificAtlantic(heights = {{10,10,10}, {10,1,10}, {10,10,10}});
    for(auto a: ans) cout << to_string(a) << endl;
}