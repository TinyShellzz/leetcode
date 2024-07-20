#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        if(len1 == 0) {
            if(len2%2 == 1) {
                return nums2[len2/2];
            } else {
                return (double)(nums2[len2/2]+nums2[len2/2-1])/2;
            }
        }

        // partition, nums1 and nums2 depart in to two 
        // such that elements amount in part1_nums1+part1_nums2 and part2_nums1+part2_nums2 are equal
        if(len%2 == 0) {
            int left = 0, right = len1;     // partition place range in nums1

            while(left <= right) {
                int cut1 = (left+right)/2;  // nums1: divide in to [0, cut1-1] and [cut1, len1-1];
                int cut2 = len/2 - cut1;  // nums2: divide in to [0, cut2-1] and [cut2, len2-1];
                // elements in [0, cut1-1]+[0, cut2-1] and [cut1, len1-1]+[cut2, len2-1] are equal;

                int l1 = cut1==0 ? INT32_MIN : nums1[cut1-1];    // cut1-1
                int r1 = cut1==len1 ? INT32_MAX : nums1[cut1];   // cut1
                int l2 = cut2==0 ? INT32_MIN : nums2[cut2-1];    // cut2-1
                int r2 = cut2==len2 ? INT32_MAX : nums2[cut2];   // cut2
                if(l1 <= r2 && l2 <= r1) {    // if this is a valid partition, then find the answer
                    return (double)(max(l1, l2)+min(r1, r2))/2;
                } else {
                    if(l1 > r2) {
                        right = cut1-1;
                    } else if(l2 > r1) {
                        left = cut1+1;
                    }
                }
            }
        } else {
            int left = 0, right = len1;

            while(left <= right) {
                int cut1 = (left+right)/2;
                int cut2 = (len+1)/2 - cut1;
                // elements in [0, cut1-1]+[0, cut2-1]+1 and [cut1, len1-1]+[cut2, len2-1] are equal;

                int l1 = cut1==0 ? INT32_MIN : nums1[cut1-1];    // cut1-1
                int r1 = cut1==len1 ? INT32_MAX : nums1[cut1];   // cut1
                int l2 = cut2==0 ? INT32_MIN : nums2[cut2-1];    // cut2-1
                int r2 = cut2==len2 ? INT32_MAX : nums2[cut2];   // cut2
                if(l1 <= r2 && l2 <= r1) {    // if this is a valid partition, then find the answer
                    return max(l1, l2);
                } else {
                    if(l1 > r2) {
                        right = cut1-1;
                    } else if(l2 > r1) {
                        left = cut1+1;
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution so;
    vector<int> nums1, nums2;

    cout << so.findMedianSortedArrays(nums1 = {2}, nums2 = {}) << endl;
}