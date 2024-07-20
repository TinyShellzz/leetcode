#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>

struct my_hash {
    size_t operator()(pair<int, int> const& p) const {
        hash<int> h;

        return h(p.first)^h(p.second);
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, my_hash> mem;

        return solve(nums, nums.size()-1, target, mem);
    }

    int solve(vector<int>& nums, int i, int target, unordered_map<pair<int, int>, int, my_hash>& mem) {
        if(i == -1 && target == 0) return 1;
        if(i == -1) return 0;
        auto f = mem.find({i, target});
        if(f != mem.end()) return f->second;

        int ret = solve(nums, i-1, target-nums[i], mem) + solve(nums, i-1, target+nums[i], mem);
        mem[{i, target}] = ret;

        return ret;
    }
};

int main() {
    Solution so;
    vector<int> input;

    cout << so.findTargetSumWays(input = {1}, 1) << endl;
}