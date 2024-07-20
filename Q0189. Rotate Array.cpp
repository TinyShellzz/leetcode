#include "utils/headers.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        vector<int> tmp(nums.begin(), nums.begin()+len-k);
        // memcpy(&(nums[0]), &(nums[len-k]), k*sizeof(int));      // may overlapping, use memmove
        memmove(&(nums[0]), &(nums[len-k]), k*sizeof(int));
        memcpy(&(nums[k]), &(tmp[0]), (len-k)*sizeof(int));
    }
};

int main() {
    Solution so;
    vector<int> nums = {1,2,3};

    so.rotate(nums, 2);
    cout << to_string(nums) << endl;
}