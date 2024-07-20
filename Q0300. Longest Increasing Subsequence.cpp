#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <set>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<pair<int, int>> mem;

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            auto low = mem.lower_bound({nums[i], 0});
            int mx = 1;
            for(auto it = low; it != mem.begin();) {
                it--;
                mx = max(mx, 1+it->second);
            }
            if(ans < mx) ans = mx;
            mem.insert({nums[i], mx});
        }
        
        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums = {0,1,0,3,2,3};

    cout << so.lengthOfLIS(nums) << endl;
}