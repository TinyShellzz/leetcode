#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> umap;

        for(int i = 0; i < nums.size(); i++) {
            auto f = umap.find(nums[i]);
            if(f == umap.end()) {
                umap[nums[i]] = vector<int>(1, i);
            } else {
                f->second.push_back(i);
            }
        }

        int ans = 0;
        for(auto& e: umap) {
            ans += count_pairs(e.second, k);
        }

        return ans;
    }

    int count_pairs(vector<int> v, int k){
        int cur_pair = v.size()-1;

        int ret = 0;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                if(j == i) continue;
                if(v[j]*v[i]%k == 0) ret++;
            }
        }
        ret /= 2;   // exclude duplicates

        return ret;
    }
};

int main() {
    Solution so;
    vector<int> nums;

    cout << so.countPairs(nums = {10,2,3,4,9,6,3,10,3,6,3,9,1}, 4) << endl;
}