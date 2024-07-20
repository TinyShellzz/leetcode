#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

struct cmp_less {
    bool operator()(vector<int> const& a, vector<int> const& b) const {
        return a.at(0) > b.at(0);
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool visited[m][n];
        memset(visited, false, sizeof(visited));

        priority_queue<vector<int>, vector<vector<int>>, cmp_less> pq;     // (elevation, i, j)
        pq.push({grid[0][0], 0, 0});
        int ans = grid[0][0];
        while(pq.size()) {
            while(visited[pq.top().at(1)][pq.top().at(2)]) pq.pop();
            vector<int> top = pq.top();
            pq.pop();
            int i = top[1], j = top[2];
            if(ans < top[0]) ans = top[0];
            if(i == m-1 && j == n-1) {
                return ans;
            }
            visited[i][j] = true;

            if(i-1 >= 0 && !visited[i-1][j]) pq.push({grid[i-1][j], i-1, j});
            if(i+1 < m && !visited[i+1][j]) pq.push({grid[i+1][j], i+1, j});
            if(j-1 >= 0 && !visited[i][j-1]) pq.push({grid[i][j-1], i, j-1});
            if(j+1 < n && !visited[i][j+1]) pq.push({grid[i][j+1], i, j+1});
        }

        return INT32_MAX;
    }
};

int main() {
    Solution so;
    vector<vector<int>> grid;
    
    // cout << so.swimInWater(grid = {{0,2}, {1,3}}) << endl;
    cout << so.swimInWater(grid = {{0,1,2,3,4}, {24,23,22,21,5}, {12,13,14,15,16}, {11,17,18,19,20}, {10,9,8,7,6}}) << endl;
}