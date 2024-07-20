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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset = {};
        unordered_set<int> ret = {};

        // insert all element in nums1 to uset
        for(int val: nums1) uset.insert(val);

        // find duplicates
        for(int val: nums2) {
            auto f = uset.find(val);
            if(f != uset.end()) ret.insert(val);
        }

        return vector<int>(ret.begin(), ret.end());
    }
};