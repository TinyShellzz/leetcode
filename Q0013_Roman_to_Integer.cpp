#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int pre = umap[s[0]];    // previous
        int res = 0;
        for(int i = 1; i < s.length(); i++) {
            int cur = umap[s[i]];
            if(pre < cur) res -= pre;   // like IV IX, res -= umap['I']
            else res += pre;
            pre = cur;
        }
        res += pre;

        return res;
    }
};

int main(){
    Solution so = Solution();
    cout << so.romanToInt("III") << endl;
    cout << so.romanToInt("LVIII") << endl;
    cout << so.romanToInt("MCMXCIV") << endl;
    cout << so.romanToInt("MMMCMXCIX") << endl;
    cout << so.romanToInt("I") << endl;
    cout << so.romanToInt("V") << endl;
}