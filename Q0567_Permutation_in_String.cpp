#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int L = 0, R = L+s1.size()-1;
        int hasher[26];
        memset(hasher, 0, sizeof(hasher));

        for(int i = 0; i < s1.size(); i++) {
            hasher[s1[i]-'a']--; 
        }
        for(int i = 0; i < s1.size(); i++) {
            hasher[s2[i]-'a']++;
        }

        while(true) {
            bool is_true = true;
            for(int i = 0; i < 26; i++) {
                if(hasher[i]) { is_true = false; break; }
            }
            if(is_true) return true;

            R++;
            if(R == s2.size()) break;
            hasher[s2[L]-'a']--; hasher[s2[R]-'a']++;
            L++;
        }

        return false;
    }
};

int main() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << endl;
}