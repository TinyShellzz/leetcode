#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

#include <queue>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        vector<bool> visited = vector<bool>(len, false);

        vector<int> v = vector<int>(1, 0);
        visited[0] = true;
        priority_queue<pair<int, int>> pq;
        int ans = 0;
        int i = 0;
        while(v.size() != len) {
            for(int j = 0; j < len; j++) {
                if(!visited[j]) {
                    pq.push({-abs(points[i][0]-points[j][0]) - abs(points[i][1]-points[j][1]), j});
                }
            }
            while(visited[pq.top().second]) {
                pq.pop();
            }

            ans -= pq.top().first;
            visited[pq.top().second] = true;
            i = pq.top().second;
            v.push_back(i);
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<vector<int>> points;

    cout << so.minCostConnectPoints(points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}}) << endl;
}