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

struct Trie {
    unordered_set<Trie *> children[26];
};

class Solution {
    unordered_map<Trie*, bool> visited;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie *root = new Trie(); visited[root] = false;
        vector<vector<Trie*>> trs = vector<vector<Trie*>>(m, vector<Trie*>(n, NULL));

        // create Trie Node
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                trs[i][j] = new Trie();
                root->children[board[i][j]-'a'].insert(trs[i][j]);
                visited[trs[i][j]] = false;
            }
        }

        // onstruct Trie
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i-1 >= 0) trs[i][j]->children[board[i-1][j]-'a'].insert(trs[i-1][j]);
                if(i+1 < m) trs[i][j]->children[board[i+1][j]-'a'].insert(trs[i+1][j]);
                if(j-1 >= 0) trs[i][j]->children[board[i][j-1]-'a'].insert(trs[i][j-1]);
                if(j+1 < n) trs[i][j]->children[board[i][j+1]-'a'].insert(trs[i][j+1]);
            }
        }

        vector<string> ans;
        for(string& w: words) {
            if(search(root, w, 0)) ans.push_back(w);
        }

        return ans;
    }

    bool search(Trie *root, string const& target, int start) {
        visited[root] = true;

        Trie *cur = root;
        for(int i = start; i < target.size(); i++) {
            if(cur->children[target[i]-'a'].empty()) {
                visited[root] = false;
                return false;
            }
            for(auto c: cur->children[target[i]-'a']) {
                if(!visited[c] && search(c, target, i+1)) {
                    visited[root] = false;
                    return true;
                }
            }
            visited[root] = false;
            return false;
        }

        visited[root] = false;
        return true;
    }
};

int main() {
    Solution so;
    vector<vector<char>> board;
    vector<string> words;

    cout << to_string(so.findWords(board = {{'a', 'a'}, {'a','a'}}, words = {"aaaaa"})) << endl;
    cout << to_string(so.findWords(board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}}, words = {"oath","pea","eat","rain"})) << endl;
}