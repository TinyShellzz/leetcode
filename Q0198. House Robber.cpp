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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0]; dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];

        for(int i = 3; i < n; i++) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }

        return max(dp[n-1], dp[n-2]);
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.rob(nums = {1,2,3,1}) << endl;
}