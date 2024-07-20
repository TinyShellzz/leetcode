#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "utils/to_string.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            umap[copy].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& e: umap) {
            ans.push_back(e.second);
        }

        return ans;
    }
};

int main(){
    vector<string> strs;

    auto res = Solution().groupAnagrams(strs = {"eat","tea","tan","ate","nat","bat"});
    for(auto e: res) cout << to_string(e) << endl;
}