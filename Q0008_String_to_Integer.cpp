#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int in = 0;     // current index
        in = skipSpace(s, in);   // 1.skip leading whitespace

        // 2.read sign
        int sign = 1;
        if(s[in] == '-') {sign = -1; in++; }
        else if(s[in] == '+') in++;
        
        // 3.skip leading zero
        in = skipZero(s, in);

        // 3.convert to integer
        unsigned int w = 1;      // weight
        unsigned int res = 0;
        bool exceeded = false;      // res wheather exceeded
        int end = in;   // [in, end) is the range need be converted
        while(end < s.length() && '0' <= s[end] && s[end] <= '9') end++;
        if(end-in > 10) { exceeded = true; goto end1;  }
        for(int i = end-1; i >= in; i--) {
            int v = s[i] - '0';     // value of this charactor
            if(w == 1000000000 && v > 2) {exceeded = true; break;}   // exceeded
            res += v*w;
            if(res > INT32_MAX) {exceeded = true; break;}   // exceeded
            w *= 10;
        }
        end1:

        if(exceeded) return sign<0 ? INT32_MIN : INT32_MAX;
        return sign*res;
    }

    int skipSpace(string s, int start) {
        while(start < s.length() && s[start] == ' ') start++;
        return start;
    }

    int skipZero(string s, int start) {
        while(start < s.length() && s[start] == '0') start++;
        return start;
    }
};

int main(){
    Solution s = Solution();
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("-42") << endl;
    cout << s.myAtoi("33333sfdsfd") << endl;
    cout << s.myAtoi("2163912694621964") << endl;
    cout << s.myAtoi("-2163912694621964") << endl;
    cout << s.myAtoi("-2147483648") << endl;
    cout << s.myAtoi("-2147483647") << endl;
    cout << s.myAtoi("-91283472332") << endl;
}