#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <algorithm>

// Manacher Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return s;

        char *str = getAuxiliaryString(s);  // 构造辅助串
        int len = 2*s.length() + 1;
        int P[len];             // 回文半径数组
        memset(P, 0, sizeof(P));
        int R = -1, C = -1;     // 当前回文的最右边界, 及其中心
        int max = -1, mC = -1;  // 最长回文, 及其中心

        for(int i = 0; i < len; i++) {
            if(i < R) P[i] = min(P[2*C-i], R-i);    // 在最右边界内(算法核心, 去掉这句就是中心扩展法)
            while(i-P[i]-1 >= 0 && i+P[i]+1 < len && str[i-P[i]-1] == str[i+P[i]+1]) P[i]++;    // 以i为中心, 扩展半径

            int nR = i + P[i];  // i处回文的右边界
            if(nR > R) { R = nR; C = i; }       // 更新R和C
            int nL = P[i];      // i处实际回文的长度
            if(nL > max) { max = nL; mC = i; }  // 更新max和mC
        }

        // 生成结果
        int mL = mC - P[mC], mR = mC + P[mC];   // 最长回文的左右边界
        string res = "";
        for(; mL <= mR; mL++) {
            if(mL%2 == 1) res.push_back(str[mL]);
        }

        return res;
    }

    // 将 "abc" 变为 "#a#b#c#"
    char *getAuxiliaryString(string str){
        int size = str.length()*2 + 2;
        char *res = new char[size];
        res[size-1] = '\0';
        res[0] = '#';

        for(int i = 0; i < str.length(); i++) {
            res[2*i + 1] = str[i];
            res[2*i + 2] = '#';
        }

        return res;
    }
};

int main(){
    Solution s = Solution();
    cout << s.getAuxiliaryString("abcba") << endl;
    cout << s.longestPalindrome("abcba") << endl;
}