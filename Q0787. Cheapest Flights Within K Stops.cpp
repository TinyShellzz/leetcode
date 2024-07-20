#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost = vector<int>(n, -1);
        cost[src] = 0;
        if(k > n) k = n;

        vector<int> copy;
        for(int i = 0; i <= k; i++) {
            copy = cost;
            for(vector<int> e: flights) {
                int new_cost = cost[e[0]] == -1 ? -1 : cost[e[0]] + e[2];
                if(new_cost != -1) copy[e[1]] = copy[e[1]] == -1 ? new_cost : min(copy[e[1]], new_cost);
            }
            cost.swap(copy);
        }

        return cost[dst];
    }
};

int main() {
    Solution so;
    vector<vector<int>> flights;

    // cout << so.findCheapestPrice(4, flights = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}}, 0, 3, 1) << endl;
    cout << so.findCheapestPrice(3, flights = {{0,1,100}, {1,2,100}, {0,2,500}}, 0, 2, 1) << endl;
}