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
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> umap;

        for(int n: nums) {
            umap.insert({n, false});
        }

        int mx = 0;
        for(auto it = umap.begin(); it != umap.end(); it++) {
            if(!it->second) {
                int ret = consecutive(umap, it);
                if(mx < ret) mx = ret;
            }
        }
        
        return mx;
    }

    int consecutive(unordered_map<int, bool>& umap, std::__detail::_Node_iterator<std::pair<const int, bool>, false, false> it) {
        it->second = true;
        int ret = 1;

        std::__detail::_Node_iterator<std::pair<const int, bool>, false, false> left;
        std::__detail::_Node_iterator<std::pair<const int, bool>, false, false> cur = it;
        while((left = umap.find(cur->first-1)) != umap.end()) {
            cur = left;
            cur->second = true;
            ret++;
        }

        std::__detail::_Node_iterator<std::pair<const int, bool>, false, false> right;
        cur = it;
        while((right = umap.find(cur->first+1)) != umap.end()) {
            cur = right;
            cur->second = true;
            ret++;
        }

        return ret;
    }
};

int main() {
    vector<int> input;

    cout << Solution().longestConsecutive(input = {100,4,200,1,3,2}) << endl;
    cout << Solution().longestConsecutive(input = {0,3,7,2,5,8,4,6,0,1}) << endl;
}