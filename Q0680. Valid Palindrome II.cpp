#include "utils/headers.h"

class Solution {
    int deleted = false;
public:
    bool validPalindrome(string s) {
        return solve(s, 0, s.size()-1);
    }

    bool solve(string& s, int start, int stop) {
        if(start >= stop) return true;

        if(s[start] != s[stop]) {
            if(!deleted) {
                deleted = true;
                return solve(s, start+1, stop) || solve(s, start, stop-1);
            }
            else return false;
        }
        return solve(s, start+1, stop-1);
    }
};

int main() {
    Solution so;

    cout << so.validPalindrome("abc") << endl;
}