#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include "utils/to_string.h"

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> dq;

    for(int i = 0; i < k-1; i++) {
      dq.push({nums[i], i});
    }

    
    vector<int> ans = vector<int>(n-k+1);
    for(int i = k-1; i < n; i++) {
      while(!dq.empty() && dq.top().second < i-k+1) {
        dq.pop();
      }
      dq.push({nums[i], i});
      ans[i-k+1] = dq.top().first;
    }

    return ans;
  }
};

int main()
{
    vector<int> nums;
    Solution so;

    cout << to_string(so.maxSlidingWindow(nums = {9,10,9,-7,-4,-8,2,-6}, 5)) << endl;
}