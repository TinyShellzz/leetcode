#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        auto umap = unordered_map<char, int>();

        int i=0, j=0;
        int max=0;
        while(true) {
            // j++
            unordered_map<char, int>::iterator f;
            while((f = umap.find(s[j])) == umap.end()) {
                umap[s[j]] = j;
                j++;
                if(j == s.length()) {
                    max = j-i>max ? j-i : max;
                    goto END;
                }
            }
            max = j-i>max ? j-i : max;

            // i++
            int i_ = i;
            i = f->second + 1;
            for(i_; i_ < i; i_++) {
                umap.erase(umap.find(s[i_]));
            }
        }
        END:

        return max;
    }
};

int main(){
    Solution *s = new Solution();

    printf("%d", s->lengthOfLongestSubstring("abcabcbb"));
}