#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num: nums) {
            num = abs(num);                 // we just need positive num
            if(nums[num] < 0) return num;   // nums[num] is already negative, then num is the duplicate
            nums[num] = -nums[num];         // since num is visited, set nums[num] to -nums[num]
        }
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.findDuplicate(nums = {1,3,4,2,2}) << endl;
}