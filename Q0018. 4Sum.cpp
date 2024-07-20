#include "utils/headers.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        int target_copy = target;
        if(len < 4) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 3; i < len; i++) {
            while(i+1 < len && nums[i] == nums[i+1]) i++;
            for(int j = 2; j < i; j++) {
                while(j+1 < i && nums[j] == nums[j+1]) j++;

                int left = 0, right = j-1;
                target = target_copy-nums[i]-nums[j];
                if(nums[left] == nums[right]) {
                    if(nums[left] << 1 == target) ans.push_back({nums[left], nums[right], nums[j], nums[i]});
                } else {
                    while(left < right) {
                        if(left+1 < right && nums[left] == nums[left+1]) {
                            if(nums[left] << 1 == target) ans.push_back({nums[left], nums[left], nums[j], nums[i]});
                            while(left+1 < right && nums[left] == nums[left+1]) left++;
                        }
                        if(right-1 > left && nums[right] == nums[right-1]) {
                            if(nums[right] << 1 == target) ans.push_back({nums[right], nums[right], nums[j], nums[i]});
                            while(right-1 > left && nums[right] == nums[right-1]) right--;
                        }

                        if(nums[left]+nums[right] < target) {
                            left++;
                        } else if(nums[left]+nums[right] > target) {
                            right--;
                        } else {
                            ans.push_back({nums[left], nums[right], nums[j], nums[i]});
                            left++;
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    so.fourSum(nums = {1,0,-1,0,-2,2}, 0);
}