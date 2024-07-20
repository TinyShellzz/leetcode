#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "utils/to_string.h"

struct Trie1 {
    char val;
    unordered_set<Trie1 *> children[26];
    Trie1(){}
    Trie1(char c): val(c) {}
};
struct Trie2 {
    Trie2 *children[26];
    bool endOfWord = false;
    Trie2(){ memset(children, 0, sizeof(children)); }
};
class Solution {
    unordered_map<Trie1*, bool> visited;
    unordered_set<string> ans;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie1 *root1 = new Trie1(0); visited[root1] = false;
        vector<vector<Trie1*>> trs = vector<vector<Trie1*>>(m, vector<Trie1*>(n, NULL));

        // create Trie1 Node
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                trs[i][j] = new Trie1(board[i][j]);
                root1->children[board[i][j]-'a'].insert(trs[i][j]);
                visited[trs[i][j]] = false;
            }
        }

        // construct Trie1
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i-1 >= 0) trs[i][j]->children[board[i-1][j]-'a'].insert(trs[i-1][j]);
                if(i+1 < m) trs[i][j]->children[board[i+1][j]-'a'].insert(trs[i+1][j]);
                if(j-1 >= 0) trs[i][j]->children[board[i][j-1]-'a'].insert(trs[i][j-1]);
                if(j+1 < n) trs[i][j]->children[board[i][j+1]-'a'].insert(trs[i][j+1]);
            }
        }

        // constrect Trie2
        Trie2 *root2 = new Trie2();
        for(string& w: words) {
            Trie2 *cur = root2;
            for(char c: w) {
                if(cur->children[c-'a']) {
                    cur = cur->children[c-'a'];
                } else {
                    cur->children[c-'a'] = new Trie2();
                    cur = cur->children[c-'a'];
                }
            }

            cur->endOfWord = true;
        }

        ans.clear();
        solve(root2, root1, "");    // find all matchs

        return vector<string>(ans.begin(), ans.end());
    }

    void solve(Trie2 *root2, Trie1 *root1, string s) {
        for(int i = 0; i < 26; i++) {
            if(root2->children[i] && !root1->children[i].empty()) {
                for(auto c1: root1->children[i]) {
                    if(!visited[c1]) {
                        visited[c1] = true;
                        string str = s;
                        str.push_back(i+'a');
                        if(root2->children[i]->endOfWord) {
                            ans.insert(str);
                        }
                        solve(root2->children[i], c1, str);
                    }
                }
            }
        }

        visited[root1] = false;
    }
};

int main() {
    Solution so;
    vector<vector<char>> board;
    vector<string> words;

    cout << to_string(so.findWords(board = {{'a', 'a'}, {'a','a'}}, words = {"aaaaa"})) << endl;
    cout << to_string(so.findWords(board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}}, words = {"oath","pea","eat","rain"})) << endl;
    cout << to_string(so.findWords(board = {{'a','b','c'}, {'a','e','d'}, {'a','f','g'}}, words = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"})) << endl;
    cout << to_string(so.findWords(board = {{'o','a','b','n'}, {'o','t','a','e'}, {'a','h','k','r'}, {'a','f','l','v'}}, words = {"oa","oaa"})) << endl;
}