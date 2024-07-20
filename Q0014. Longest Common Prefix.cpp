#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>

struct Trie {
    Trie *children[26];
    bool endOfWord = false;
    Trie(){ memset(children, 0, sizeof(children)); }
    void add(string const& str) {
        Trie *root = this;
        Trie *cur = root;
        for(char c: str) {
            if(!cur->children[c-'a']) cur->children[c-'a'] = new Trie();
            cur = cur->children[c-'a'];
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *root = new Trie();
        int size = INT32_MAX;   // max size of ans
        for(string const& str: strs) {
            if(size > str.size()) size = str.size();
            root->add(str);    // constrcut Trie
        }

        // find Trie Node that has exact one child
        bool have_child = true;
        Trie *cur = root;
        Trie *next = cur;
        string ans;
        while(have_child) {
            have_child = false;
            cur = next;
            for(int i = 0; i < 26; i++) {
                if(cur->children[i]) {
                    if(have_child) {
                        ans.pop_back();
                        goto END;
                    }
                    have_child = true;
                    if(!size) goto END;
                    ans.push_back('a'+i);
                    size--;
                    next = cur->children[i];
                }
            }
        }
        END:
        deconstruct(root);
        return ans;
    }

    void deconstruct(Trie *root) {
        for(Trie *c: root->children) {
            if(c) deconstruct(c);
        }

        delete root;
    }
};

int main() {
    Solution so;
    vector<string> input;

    cout << so.longestCommonPrefix(input = {"flower","flow","flight"}) << endl;
}