#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>
#include "utils/to_string.h"


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans = vector<bool>(l.size(), 0);

        for(int i = 0; i < l.size(); i++) {
            vector<int> vec = vector<int>(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(vec.begin(), vec.end());

            bool is_arithmetic = true;
            int com_diff = 0;
            if(vec.size() > 1) com_diff = vec[1]-vec[0];
            for(int i = 2; i < vec.size(); i++) {
                if(vec[i] - vec[i-1] != com_diff) {
                    is_arithmetic = false;
                    break;
                }
            }
            ans[i] = is_arithmetic;
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> nums, l, r;

    cout << to_string(so.checkArithmeticSubarrays(nums = {4,6,5,9,3,7}, l = {0,0,2}, r = {2,3,5})) << endl;
}