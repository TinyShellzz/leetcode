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
        int arr[nums.size()];
        memset(arr, false, sizeof(arr));    // default is false

        for(int num: nums) {
            if(arr[num]) {      // when arr[num] is already true
                return num;     // num is the duplicate
            }
            arr[num] = true;    // set visited num to true
        }
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.findDuplicate(nums = {1,3,4,2,2}) << endl;
}