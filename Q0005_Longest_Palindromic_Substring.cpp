#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <algorithm>

// check wheather string is a palindrome, start from the center and expand to the edge
class Solution {
public:
    string longestPalindrome(string s) {\
        int size = 2*s.length() - 1;
        int longest[size];

        int mx = 0, in = 0;
        for(int i = 0; i < size; i++) {
            longest[i] = longestPalindrome(s, i);
            if(mx < longest[i]) {
                mx = longest[i];
                in = i;
            }
        }

        int si, ei;
        if(in % 2 == 0) {
            si = in/2 - mx/2;
            return s.substr(si, mx);
        } else {
            si = in/2 - mx/2 + 1;
            return s.substr(si, mx);
        }
    }

    int longestPalindrome(string s, int center) {
        int si, ei;
        if(center%2 == 0) {
            si = center/2 - 1;
            ei = si + 2;
            while(si >= 0 && ei < s.length()) {
                if(s[si] == s[ei]) { si--; ei++;}
                else break;
            }
            return ei-si-1;
        } else {
            si = center/2;
            ei = si + 1;
            if(s[si--] != s[ei++]) return 0;
            while(si >= 0 && ei < s.length()) {
                if(s[si] == s[ei]) {si--; ei++;}
                else break;
            }
            return ei-si-1;
        }
    }
};

int main(){
    Solution s = Solution();
    cout << s.longestPalindrome("ccc\n");
}