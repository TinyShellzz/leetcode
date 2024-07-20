#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> vec;
        solve(nums, 0, vec);
        return ans;
    }

    void solve(vector<int>& nums, int index, vector<int>& pre) {
        if(index == nums.size()) {
            ans.push_back(pre);
            return;
        }

        solve(nums, index+1, pre);      // exclude nums[index]
        vector<int> copy = pre;
        copy.push_back(nums[index]);    // include nums[index]
        solve(nums, index+1, copy);
    }
};

int main() {
    Solution so;
    vector<int> nums;

    vector<vector<int>> ans = so.subsets(nums = {1,2,3});

    for(auto a: ans) {
        cout << to_string(a) << endl;
    }
}