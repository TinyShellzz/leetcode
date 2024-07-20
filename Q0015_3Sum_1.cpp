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
            if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;;

            for(int j = 1; j < i; j++) {
                if(j+1 < i && nums[j] == nums[j+1]) continue;

                auto low = lower_bound(nums.begin(), nums.begin()+j, target - nums[i] - nums[j]);
                if(low != nums.begin()+j && *low == target-nums[i]-nums[j]) ans.push_back({*low, nums[j], nums[i]});
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