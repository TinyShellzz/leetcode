#include "utils/headers.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        string hash[26];
        for(string& str: hash) str = "";

        int i = 0;
        int j = 0;
        int in = 0;
        while(true) {
            while(j < s.size() && s[j] != ' ') j++;
            string const& cur = s.substr(i, j-i);

            // bijection from pattern to s
            if(hash[pattern[in]-'a'] == "") {
                hash[pattern[in]-'a'] = s.substr(i, j-i);
            } else {
                if(hash[pattern[in]-'a'] != s.substr(i, j-i)) return false;
            }

            // bijection from s to pattern
            auto f = umap.find(cur);
            if(f == umap.end()) {
                umap[cur] = pattern[in];
            } else {
                if(f->second != pattern[in]) return false;
            }
            in++;
            if(j == s.size() && in == pattern.size()) return true;
            if(in == pattern.size() || j == s.size()) break;
            i = j;
            while(i < s.size() && s[i] == ' ') i++;
            j = i;
        }

        return false;
    }
};

int main() {
    Solution so;

    cout << so.wordPattern("abba", "dog cat cat fish") << endl;
}