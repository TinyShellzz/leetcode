#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        #define n numRows
        if(n == 1) {
            return s;
        }


        int len = s.length();
        string res = "";

        int j = 0, k = 2*n - 2;
        while(true) {
            res.push_back(s[k*j]);
            if(k*++j >= len) break; 
            // res.append(n-2, ' ');
        }

        // res.push_back('\n');
        for(int i = 1; i < n - 1; i++) {
            j = 0;
            if(k*j + i >= len) break;
            while(true) {
                res.push_back(s[k*j + i]);
                if(k*j + k - i >= len) break;
                // res.append(n-2-i, ' ');
                res.push_back(s[k*j + k - i]);
                if(k*++j + i >= len) break;
                // res.append(i-1, ' ');
            }

            // res.push_back('\n');
        }

        if(n-1 >= len) goto END;
        j = 0;
        while(true) {
            res.push_back(s[k*j+n-1]);
            if(k*++j+n-1 >= len) break;
            // res.append(n-2, ' ');
        }
        // res.push_back('\n');
        END:

        return res;
    }
};

int main(){
    Solution s = Solution();
    cout << s.convert("ABC", 3);
    return 0;
}