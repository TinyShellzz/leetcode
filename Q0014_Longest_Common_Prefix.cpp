#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());     // 字典排序

        auto first = strs.begin();
        auto last = strs.end() - 1;
        int min_len = min(first->length(), last->length());
        
        int res = 0;
        for(; res < min_len; res++) {
            if((*first)[res] != (*last)[res]) break;
        }

        return string(strs[0], 0, res);
    }
};

int main(){
    Solution so = Solution();
    vector<string> strs;
    cout << so.longestCommonPrefix(strs = {"flower","flow","flight"}) << endl;
    cout << so.longestCommonPrefix(strs = {"dog","racecar","car"}) << endl;
    cout << so.longestCommonPrefix(strs = {"flower","flow","flowight"}) << endl;
}