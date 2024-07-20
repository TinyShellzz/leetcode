#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <deque>
#include "utils/to_string.h"

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<pair<int, int>> dq;

    for(int i = 0; i < k-1; i++) {
      while(!dq.empty() && dq.back().second <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back({i, nums[i]});
    }

    
    vector<int> ans(n-k+1);
    for(int i = k-1; i < n; i++) {
      while(!dq.empty() && dq.back().second <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back({i, nums[i]});
      if(dq.front().first == i-k) dq.pop_front();
      ans[i-k+1] = dq.front().second;
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