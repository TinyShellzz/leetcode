#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include "utils/to_string.h"

struct my_hasher {
    size_t operator()(vector<int> const& vec) const {
        size_t ret = 0;
        hash<int> hash_int = hash<int>();
        for(int e: vec) {
            ret ^= hash_int(e);
        }

        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<int>> hasher = vector<vector<int>>(len, vector<int>(26, 0));

        for(int i = 0; i < len; i++) {
            for(char ch: strs[i]) {
                hasher[i][ch-'a']++;
            }
        }

        unordered_map<vector<int>, vector<int>, my_hasher> umap;
        for(int i = 0; i < len; i++) {
            auto f = umap.find(hasher[i]);
            if(f == umap.end()) {
                umap[hasher[i]] = vector<int>(1, i);
            } else {
                umap[hasher[i]].push_back(i);
            }
        }

        vector<vector<string>> ans;
        for(auto& pair: umap) {
            vector<int> indices = pair.second;
            vector<string> sub_ans;
            for(int in: indices) {
                sub_ans.push_back(strs[in]);
            }
            ans.push_back(sub_ans);
        }

        return ans;
    }
};

int main(){
    vector<string> strs;

    auto res = Solution().groupAnagrams(strs = {"eat","tea","tan","ate","nat","bat"});
    for(auto e: res) cout << to_string(e) << endl;
}