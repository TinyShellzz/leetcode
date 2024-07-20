#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include "utils/to_string.h"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> umap;       // key: groupSize, Value: people ID

        for(int i = 0; i < groupSizes.size(); i++) {
            auto f = umap.find(groupSizes[i]);
            if(f == umap.end()) {
                umap[groupSizes[i]] = vector<int>();
                umap[groupSizes[i]].push_back(i);
            } else umap[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> res;
        int group_id = 0;
        for(auto it = umap.begin(); it != umap.end(); it++) {
            int size = it->first;   // size of this group
            vector<int> mems = it->second;  // members of this group
            for(int i = 0; i < mems.size();) {
                res.push_back(vector<int>());
                for(int j = 0; j < size; j++) {
                    res[res.size()-1].push_back(mems[i+j]); // add members to group
                }

                i += size;
            }
        }

        return res;
    }
};

int main(){
    Solution so;
    vector<int> groupSizes;

    cout << to_string(so.groupThePeople(groupSizes = {3,3,3,3,3,1,3})) << endl;
}