#include "utils/headers.h"

class Solution {
    int n;
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        this->n = n;
        int dp[n][n];
        memset(dp, 0 , sizeof(dp));
        return solve(nums, 0, nums.size()-1, &dp);
    }

    int solve(vector<int>& nums, int i, int j, void *dp) {
        if(i < 0 || i > j) return 0;
        int *dp_ = (int *)dp;
        if(*(dp_+i*n+j)) return *(dp_+i*n+j);

        int mx = INT32_MIN;
        for(int k = i; k <= j; k++) {
            int a = i==0 ? 1 : nums[i-1];
            int b = j==nums.size()-1 ? 1 : nums[j+1];
            int res1 = solve(nums, i, k-1, dp);
            int res2 = solve(nums, k+1, j, dp);
            mx = max(mx, a*nums[k]*b + res1 + res2);
        }
        *(dp_+i*n+j) = mx;

        return mx;
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.maxCoins(input = {3,1,5,8}) << endl;
}