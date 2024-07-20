#include "utils/headers.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] <= nums[i+1]) continue;

            if(modified) return false;
            if(i-1 >= 0 && nums[i-1] > nums[i+1]) {
                nums[i+1] = nums[i];
            }
            modified = true;
        }

        return true;
    }
};

int main() {
    vector<int> nums;
    Solution so;

    cout << so.checkPossibility(nums = {4,2,3}) << endl;
}