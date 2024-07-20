#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int L=0, R=0;
    vector<int> ans;
    
    int mx_in = 0;
    for(;R < k; R++) {
      if(nums[mx_in] <= nums[R]) mx_in = R;
    }
    ans.push_back(nums[mx_in]);
    
    R--;
    while(R < nums.size()-1) {
      if(L == mx_in) {
        L++; R++;
        mx_in = L;
        for(int i=L; i<=R; i++) {
          if(nums[mx_in] <= nums[i]) mx_in = i;
        }
        ans.push_back(nums[mx_in]);
      } else {
        L++; R++;
        if(nums[mx_in] <= nums[R]) mx_in = R;
        ans.push_back(nums[mx_in]);
      }
    }
    
    return ans;
  }
};

int main()
{
    vector<int> nums;
    Solution so;

    cout << to_string(so.maxSlidingWindow(nums = {1,3,-1,-3,5,3,6,7}, 3)) << endl;
}