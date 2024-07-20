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
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        bool visited[n];
        memset(visited, 0, sizeof(visited));

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_less> pq;
        pq.push({0, -1});
        while(true) {
            while(visited[pq.top().second]) pq.pop();

            pair<int, int> top = pq.top();
            pq.pop();
            int i = top.second;
            if(i >= 0) visited[i] = true;
            if(i == n-1 || i == n-2) return top.first;
            if(i+1 < n && !visited[i+1]) {
                pq.push({top.first+cost[i+1], i+1});
            }
            if(i+2 < n && !visited[i+2]) {
                pq.push({top.first+cost[i+2], i+2});
            }
        }
    }
};

int main() {
    Solution so;
    vector<int> cost;

    cout << so.minCostClimbingStairs(cost = {10,15,20}) << endl;
}