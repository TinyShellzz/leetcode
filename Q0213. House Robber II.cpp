#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int dp1[n];
        memset(dp1, 0, sizeof(dp1));
        dp1[0] = nums[0]; dp1[1] = nums[1];
        dp1[2] = nums[2] + dp1[0];
        for(int i = 3; i < n-1; i++) {
            dp1[i] = nums[i] + max(dp1[i-2], dp1[i-3]);
        }
        int ans1 = max(dp1[n-2], dp1[n-3]);

        if(n == 3) return max(ans1, nums[2]);
        int dp2[n];
        memset(dp2, 0, sizeof(dp2));
        dp2[1] = nums[1]; dp2[2] = nums[2];
        dp2[3] = nums[3] + dp2[1];
        for(int i = 4; i < n; i++) {
            dp2[i] = nums[i] + max(dp2[i-2], dp2[i-3]);
        }
       int ans2 = max(dp2[n-1], dp2[n-2]);

       return max(ans1, ans2);
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.rob(nums = {200,3,140,20,10}) << endl;
}