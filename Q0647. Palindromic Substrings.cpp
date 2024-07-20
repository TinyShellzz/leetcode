#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int countSubstrings(string s) {
        vector<int> mana = manacher(s);

        int ans = 0;
        for(int i = 0; i < mana.size(); i++) {
            ans += (mana[i] + i%2)/2;
        }
        return ans;
    }

    vector<int> manacher(string& s) {
        int len = s.size();
        int n = 2*len+1;
        string str = string(n, '#');
        for(int i = 0; i < len; i++) str[2*i+1] = s[i];
        
        vector<int> ret = vector<int>(n, 0);
        int border = 0;
        int c_i = 0;
        for(int i = 0; i < n; i++) {
            if(i < border)  ret[i] = min(ret[2*c_i-i], border-i);
            while(i-ret[i]-1 >= 0 && i+ret[i]+1 < n && str[i-ret[i]-1] == str[i+ret[i]+1]) ret[i]++;
            if(ret[i]+i > border) {
                border = ret[i]+i;
                c_i = i;
            }
        }

        return ret;
    }
};

int main() {
    Solution so;

    cout << so.countSubstrings("abc") << endl;
}