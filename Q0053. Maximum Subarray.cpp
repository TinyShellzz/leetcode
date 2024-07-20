#include "utils/headers.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left, right;
        left = right = 0;

        int sum = 0;
        int ans = INT32_MIN;
        while(right != nums.size()) {
            sum += nums[right++];
            if(sum < 0) {
                ans = max(sum, ans);    // if nums is all negative, return the max one
                sum = 0;
                left = right;
            } else {
                ans = max(sum, ans);
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.maxSubArray(input = {-9, -7, -1, -5}) << endl;
}