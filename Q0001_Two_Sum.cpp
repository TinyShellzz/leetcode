#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto umap = unordered_map<int, int>();      // <value, nums_in>
        int nums_in = 0;   // current index in nums
        for(auto i: nums) {
            umap[i] = nums_in;
            nums_in++;
        }

        nums_in = 0;
        for(auto i: nums) {
            auto f = umap.find(target - i);
            if(f != umap.end() && nums_in != f->second) {
                return {nums_in, f->second};
            }
            nums_in++;
        }

        return {};
    }
};

Solution *s;

int main(){
    s = new Solution();

    vector<int> nums = {3,3};
    auto res = s->twoSum(nums, 6);
    for(auto i: res) {
        cout << i << ' ';
    }
    cout << endl;
}