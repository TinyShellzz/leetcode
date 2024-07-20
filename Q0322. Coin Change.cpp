#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), [](int a, int b){ return a>b; });
        unordered_map<int, int> mem;

        return solve(coins, amount, mem);
    }

    int solve(vector<int>& coins, int amount, unordered_map<int, int>& mem) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        auto f = mem.find(amount);
        if(f != mem.end()) return f->second;

        int mini = INT32_MAX;
        for(int c: coins) {
            int res = solve(coins, amount-c, mem);
            if(res == -1) continue;
            if(res+1 < mini) mini = res+1;
        }

        mini = mini == INT32_MAX ? -1 : mini;
        mem[amount] = mini;
        return mini;
    }
};

int main() {
    Solution so;
    vector<int> coins;

    cout << so.coinChange(coins = {1}, 0) << endl;
}