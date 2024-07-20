#include "utils/headers.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums);
        return nums;
    }

    void build_heap(vector<int>& nums){
        int len = nums.size();
        for(int i = len<<1; i >= 0; i--) {     // (len - 2)/2 is the first node need heapify, we just use len/2 instead
            heapify(nums, i, len);
        }
    }

    void heapify(vector<int>& nums, int n, int limit){
        if(n >= limit) return;
        int lc = 2*n+1;
        int rc = 2*n+2;

        heapify(nums, lc, limit);   // limit denote the edge of heap-tree
        heapify(nums, rc, limit);

        int mx = n;
        if(lc < limit && nums[lc] > nums[mx]) mx = lc;
        if(rc < limit && nums[rc] > nums[mx]) mx = rc;
        swap(nums[n], nums[mx]);
    }

    void heap_sort(vector<int>& nums) {
        build_heap(nums);

        int limit = nums.size();
        while(limit != 0) {
            swap(nums[0], nums[limit-1]);
            limit--;
            heapify(nums, 0, limit);
        }
    }
};

int main(){
    Solution so;
    vector<int> nums;

    cout << to_string(so.sortArray(nums = {2,1,3})) << endl;
}