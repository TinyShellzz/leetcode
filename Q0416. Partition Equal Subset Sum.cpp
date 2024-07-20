#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;

        int target = 0;
        for(int num: nums) target += num;
        if(target%2 == 1) return false;
        target /= 2;

        unordered_set<int> uset;
        uset.insert(0);
        for(int i = 0; i < n; i++) {
            auto copy = uset;
            for(int e: copy) {  // you cant modify uset while iterating it
                if(e < target) uset.insert(e+nums[i]);
            }
            if(uset.find(target) != uset.end()){
                int c = uset.count(target);
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.canPartition(nums = {4,4,4,4,4,4,4,4,8,8,8,8,8,8,8,8,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,20,20,20,20,20,20,20,20,24,24,24,24,24,24,24,24,28,28,28,28,28,28,28,28,32,32,32,32,32,32,32,32,36,36,36,36,36,36,36,36,40,40,40,40,40,40,40,40,44,44,44,44,44,44,44,44,48,48,48,48,48,48,48,48,52,52,52,52,52,52,52,52,56,56,56,56,56,56,56,56,60,60,60,60,60,60,60,60,64,64,64,64,64,64,64,64,68,68,68,68,68,68,68,68,72,72,72,72,72,72,72,72,76,76,76,76,76,76,76,76,80,80,80,80,80,80,80,80,84,84,84,84,84,84,84,84,88,88,88,88,88,88,88,88,92,92,92,92,92,92,92,92,96,96,96,96,96,96,96,96,97,99}) << endl;
}