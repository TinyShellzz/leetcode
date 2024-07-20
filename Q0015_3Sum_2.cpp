#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>
#include <algorithm>
#include "utils/my_hasher.h"
#include "utils/to_string.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;


        vector<vector<int>> ans;
        auto low_i = lower_bound(nums.begin(), nums.end(), target);
        int i = distance(nums.begin(), low_i);
        for(; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;

            int L = 0, R = i-1;
            int cur_target = target - nums[i];
            while(true) {
                if(L < R && nums[L] == nums[L+1]) {
                    if(2*nums[L] == cur_target) ans.push_back({nums[L], nums[L], nums[i]});
                    while(L < R && nums[L] == nums[L+1]) L++;
                }
                if(L < R && nums[R] == nums[R-1]) {
                    if(2*nums[R] == cur_target) ans.push_back({nums[R], nums[R], nums[i]});
                    while(L < R && nums[R] == nums[R-1]) R--;
                }
                if(L >= R) break;

                if(nums[L] + nums[R] > cur_target) R--;
                else if(nums[L] + nums[R] < cur_target) L++;
                else {
                    ans.push_back({nums[L], nums[R], nums[i]});
                    L++;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution so = Solution();
    vector<int> nums;
    for(auto e: so.threeSum(nums = {-1,0,1,0})) cout << to_string(e) << endl;
    cout << "--------" << endl;
    for(auto e: so.threeSum(nums = {-1,0,1,2,-1,-4})) cout << to_string(e) << endl;
    cout << "--------" << endl;
    for(auto e: so.threeSum(nums = {0,1,1})) cout << to_string(e) << endl;
    cout << "--------" << endl;
    for(auto e: so.threeSum(nums = {0,0,0})) cout << to_string(e) << endl;
    cout << "--------" << endl;
}