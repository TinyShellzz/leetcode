#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        // INT32_MIN denotes impossible state
        vector<vector<int>> mem = vector<vector<int>>(len, vector<int>(3, INT32_MIN));
        return max(solve(prices, len-1, 1, mem), solve(prices, len-1, 2, mem));     // sate 0 is impossible for answer, because must sell to reach this state.
    }

    int solve(vector<int>& prices, int i, int state, vector<vector<int>>& mem) {
        if(i==0) {
            if(state == 0) {    // have a stock  (state 2&0 can reach this state)
                mem[0][state] = -prices[0];
                return -prices[0];
            }
            if(state == 1) {    // just sell a stock, can't buy (state 0 can reach this state)
                mem[0][state] = INT32_MIN;
                return INT32_MIN;       // impossible state
            }
            if(state == 2) {    // don't hava stock (state 1&2 can reach this state)
                mem[0][state] = 0;
                return 0;
            }
        }
        if(mem[i][state] != INT32_MIN) return mem[i][state];

        int ret;
        if(state == 0) {        // from state 2 or 0, we only keep the larger one
            int res = solve(prices, i-1, 2, mem);
            ret = max(res == INT32_MIN ? INT32_MIN : res-prices[i], solve(prices, i-1, 0, mem));
        }
        if(state == 1) {        // from state 0
            int res = solve(prices, i-1, 0, mem);
            ret = res == INT32_MIN ? INT32_MIN : res+prices[i];
        }
        if(state == 2) {        // from state 1 or 2
            ret = max(solve(prices, i-1, 1, mem), solve(prices, i-1, 2, mem));
        }

        mem[i][state] = ret;

        return ret;
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.maxProfit(input = {1,2,3,0,2}) << endl;
}