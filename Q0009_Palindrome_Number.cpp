#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;

        // convert x to string
        char s[10];
        int len = 0;
        while(x) {
            s[len++] = x%10;
            x /= 10;
        }

        // check s weather is Palindrome
        int L = 0, R = len - 1;     // pointer point to Left and Right Border
        bool isPa = true;
        while(L < R) {
            if(s[L++] != s[R--]) {
                isPa = false; break;
            }
        }

        return isPa;
    }
};

int main(){
    Solution so = Solution();
    cout << so.isPalindrome(121) << endl;
    cout << so.isPalindrome(1234554321) << endl;
    cout << so.isPalindrome(123454321) << endl;
    cout << so.isPalindrome(-121) << endl;
    cout << so.isPalindrome(10) << endl;
    cout << so.isPalindrome(INT32_MAX) << endl;
}