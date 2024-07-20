#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size();
        int total = 0;

        for(int bitmask = 0; bitmask < (1<<len); bitmask++) {
            int cur_total = 0;
            for(int i = 0; i < len; i++) {
                if(1&(bitmask>>i)) cur_total ^= nums[i];    // if i match bitmask
            }
            total += cur_total;
        }

        return total;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.subsetXORSum(nums = {5,1,6}) << endl;
}