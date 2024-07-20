#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

struct Trie {
    Trie *children[26];
    bool endOfWord = false;
    Trie(){ memset(children, 0, sizeof(children)); }
};

class WordDictionary {
    Trie *root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = root;
        for(char c: word) {
            auto children = cur->children;
            if(children[c-'a']) cur = children[c-'a'];
            else { cur = new Trie(); children[c-'a'] = cur; }
        }

        cur->endOfWord = true;
    }
    
    bool search(Trie *tr, string const& word) {
        Trie *cur = tr;
        for(int i = 0; i < word.size(); i++) {
            auto children = cur->children;
            if(word[i] != '.' && !children[word[i]-'a']) return false;
            if(word[i] == '.') {
                bool match = false;
                string const& target = word.substr(i+1, word.size()-i-1);
                for(int i = 0; i < 26; i++) {
                    if(children[i] && search(children[i], target)) {
                        match = true;
                        break;
                    }
                }
                return match;
            } else cur = children[word[i]-'a'];
        }

        return cur->endOfWord;
    }

    bool search(string word) {
        return search(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */