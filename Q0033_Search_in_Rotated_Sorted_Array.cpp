#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left < right) {
            if(nums[left] < nums[right]) {
                auto low = lower_bound(nums.begin()+left, nums.begin()+right+1, target);
                if(low != nums.begin()+right+1 && *low == target) return distance(nums.begin(), low);
                else return -1;
            }

            int mid = (left+right)/2;
            if(target >= nums[left]) {
                if(nums[mid] < nums[left]) {
                    right = mid-1;
                    continue;
                }

                if(target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if(nums[mid] > nums[right]) {
                    left = mid+1;
                    continue;
                }

                if(target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }

        return target == nums[right] ? right : -1;
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.search(input = {3, 1}, 1) << endl;
}