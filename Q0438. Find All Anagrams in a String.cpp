#include "utils/headers.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        int hasher[26];
        memset(hasher, 0, sizeof(hasher));
        int size= 0 ;
        for(char c: p) {
            if(hasher[c-'a'] == 0) size++;
            hasher[c-'a']++;
        }

        int len = s.size();
        int left = 0;
        int right = p.size();
        vector<int> ans;
        for(int i = left; i < right; i++) {
            if(hasher[s[i]-'a'] == 0) size++;
            hasher[s[i]-'a']--;
            if(hasher[s[i]-'a'] == 0) size--;
        }
        if(size == 0) ans.push_back(left);

        while(right < len) {
            if(hasher[s[left]-'a'] == 0) size++;
            hasher[s[left]-'a']++;
            if(hasher[s[left]-'a'] == 0) size--;

            if( hasher[s[right]-'a'] == 0) size++;
            hasher[s[right]-'a']--;
            if( hasher[s[right]-'a'] == 0) size--;
            left++;
            right++;

            if(size == 0) ans.push_back(left);
        }

        return ans;
    }
};

int main() {
    Solution so;

    cout << to_string(so.findAnagrams("baa", "aa")) << endl;
}