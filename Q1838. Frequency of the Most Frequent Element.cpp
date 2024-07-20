#include "utils/headers.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int left = 0, right = 0;
        while(right+1 < len) {
            int tmp = (right-left+1)*(nums[right+1]-nums[right]);
            if(sum+tmp > k) break;
            sum += tmp;
            right++;
        }

        int mx = 0;
        mx = right-left+1;
        while(right+1 < len) {
            sum += (right-left)*(nums[right+1]-nums[right]);
            sum -= nums[right]-nums[left];
            left++; right++;
            if(sum <= k) {
                while(right+1 < len) {
                    int tmp = (right-left+1)*(nums[right+1]-nums[right]);
                    if(sum+tmp > k) break;
                    sum += tmp;
                    right++;
                }
                mx = max(mx, right-left+1);
            }
        }

        return mx;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.maxFrequency(nums = {1,4,8,13}, 5) << endl;
}