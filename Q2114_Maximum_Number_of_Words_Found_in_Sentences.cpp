#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#include <vector>

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0;
        for(string str: sentences) {
            int count = count_sentence(str);
            if(mx < count) mx = count;
        }

        return mx;
    }

    int count_sentence(string &str) {
        int len = str.size();
        if(len == 0) return 0;

        int i = 0;
        int count = 1;
        while(true) {
            while(i < len && str[i] != ' ') i++;    // detect spaces
            if(i == len) break;
            count++;
            while(i < len && str[i] == ' ') i++;    // skip spaces
        }

        return count;
    }
};

int main(){
    Solution so;
    vector<string> v;

    cout << so.mostWordsFound(v = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"}) << endl;

    return 0;
}