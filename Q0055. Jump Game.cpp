#include "utils/headers.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left, right;
        left = right = 0;

        while(true) {
            int mx = 0;
            if(left > right) return false;
            for(int i = left; i <= right; i++) {
                mx = max(mx, i+nums[i]);
            }
            left = right+1;
            right = mx;
            if(right >= nums.size()-1) break;
        }

        return true;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.canJump(nums = {2,3,1,1,4}) << endl;
    cout << so.canJump(nums = {3,2,1,0,4}) << endl;
}