#include "utils/headers.h"

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        sort(nums.begin(), nums.end());

        while(left < right && nums[left]+nums[right]>target) right--;
        if(left == right) return 0;

        int ans = 0;
        int m, n;
        int pre_left = -1, pre_right = -1;
        while(true) {
            if(pre_left != left){
                m = 1;
                while(left+1 < right && nums[left] == nums[left+1]) {
                    left++;
                    m++;
                }
            }
            if(pre_right != right) {
                n = 1;
                while(left < right-1 && nums[right] == nums[right-1]) {
                    right--;
                    n++;
                }
            }
            
            if(right == left) {
                ans += 1;
            } else {
                for(int i = 0; i < m; i++) {
                    ans += 1<<(right+n-left-2+i)+1;
                }
            }

            if(left > right) break;
            pre_left = left;
            pre_right = right;
            left++;
            while(left < right && nums[left]+nums[right]>target) right--;
            if(left > right || nums[left]+nums[right]>target) break;
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.numSubseq(nums = {7,10,7,3,7,5,4}, 12) << endl;
}