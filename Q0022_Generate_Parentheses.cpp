#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
    vector<string> ans;
    int n;

public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        this->n = n;
        vector<char> stack;
        string str;
        ans.clear();
        solve(open, str, stack);

        return ans;
    }

    void solve(int open, string& str, vector<char>& stack) {
        if(open == 0) {
            for(int i = str.size(); i < 2*n; i++) {
                str.push_back(')');
            }
            ans.push_back(str); 
            return;
        }

        if(!stack.empty() && stack.back() == '(') {
            string copy = str;
            copy.push_back(')');
            vector<char> stack_copy = stack;
            stack_copy.pop_back();
            solve(open, copy, stack_copy);
        }

        stack.push_back('(');
        str.push_back('(');
        solve(open-1, str, stack);
    }
};

int main() {
    Solution so;
    
    cout << to_string(so.generateParenthesis(3)) << endl;

}