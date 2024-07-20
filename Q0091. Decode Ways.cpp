#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1) return s[0] != '0';
        vector<int> mem(n, -1);

        mem[0] = (s[0] != '0');
        mem[1] = mem[0] + (s[0] == '1' || s[0] == '2' && s[1] <= '6');

        return solve(s, n-1, mem);
    }

    int solve(string& s, int i, vector<int>& mem) {
        if(i == s.size()) return 0;
        if(mem[i] != -1) return mem[i];

        int res=0;
        if(s[i] != '0') res += solve(s, i-1, mem);
        if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') res += solve(s, i-2, mem);
        mem[i] = res;

        return res;
    }
};

int main() {
    Solution so;


    cout << so.numDecodings("06") << endl;
}