#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1;
        int j;
        string ans;
        while(true) {
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            while(j >= 0 && s[j] != ' ') j--;
            ans.append(s.substr(j+1, i - j));
            ans.push_back(' ');
            i = j;
            if(i < 0) break;
        }

        if(ans.size()) ans.pop_back();
        return ans;
    }
};