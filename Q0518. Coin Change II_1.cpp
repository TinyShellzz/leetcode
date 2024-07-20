#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> mem(len, vector<int>(amount+1, INT32_MIN));

        return solve(coins, len-1, amount, mem);
    }

    int solve(vector<int>& coins, int i, int target, vector<vector<int>>& mem) {
        if(i < 0 || target < 0) return 0;
        if(target == 0) {
            mem[i][target] = 1;
            return 1;
        }
        if(mem[i][target] != INT32_MIN) return mem[i][target];
        
        return solve(coins, i, target-coins[i], mem) + solve(coins, i-1, target, mem);
    }
};