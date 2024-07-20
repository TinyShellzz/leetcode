#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int L = 0, R = 0;   // left and right index
        int sum = 0;
        int min_l = INT32_MAX;

        while(R < nums.size()) {
            if(sum < target) {
                sum += nums[R];
                R++;
            } else {
                min_l = min(min_l, R - L);
                sum -= nums[L];
                L++;
            }
        }

        while(sum >= target) {
            min_l = min(min_l, R - L);
            sum -= nums[L];
            L++;
        }

        return min_l == INT32_MAX ? 0 : min_l;
    }  
};

int main()
{
    Solution so = Solution();
    vector<int> nums;
    cout << so.minSubArrayLen(11, nums= {1,2,3,4,5}) << endl;
    return 0;
}