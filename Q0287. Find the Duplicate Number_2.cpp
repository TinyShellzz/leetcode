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
        int low = 0, fast = 0;          // slow and fast start and 0
        while(true) {
            low = nums[low];            // slow move one step at a time
            fast = nums[nums[fast]];    // fast move two steps at a time

            if(low == fast) break;  // fast and slow meet, and slow are pointing to the meeting point
        }

        int head = 0;    // head start from the very begin
        while(true) {    // slow start at the meeting point
            head = nums[head];
            low = nums[low];

            if(low == head) return low;     // when head meets slow, we find the duplicate
        }
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.findDuplicate(nums = {1,3,4,2,2}) << endl;
}