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
    char val;
    unordered_set<Trie *> children[26];
    Trie(){}
    Trie(char c): val(c) {}
};
struct my_hasher {
    size_t operator()(pair<string, Trie*> const& a) const {
        size_t hash = 1315423911;
        string const& s = a.first;
        for(char c: s) hash ^= ((hash << 5) + c + (hash >> 2));;
        hash ^= (size_t)a.second;
        return hash;
    }
};

class Solution {
    unordered_map<Trie*, bool> visited;
    unordered_map<pair<string, Trie*>, vector<unordered_map<Trie*, bool>>, my_hasher> umap;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie *root = new Trie(0); visited[root] = false;
        vector<vector<Trie*>> trs = vector<vector<Trie*>>(m, vector<Trie*>(n, NULL));

        // create Trie Node
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                trs[i][j] = new Trie(board[i][j]);
                root->children[board[i][j]-'a'].insert(trs[i][j]);
                visited[trs[i][j]] = false;
            }
        }

        // construct Trie
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
            if(search(root, w)) ans.push_back(w);
        }

        return ans;
    }

    bool search(Trie *root, string const& target) {
        if(target.size() == 0) return true;
        visited[root] = true;

        if(root->children[target[target.size()-1]-'a'].empty()) {
            visited[root] = false;
            return false;
        }
        bool find = false;
        for(auto c: root->children[target[target.size()-1]-'a']) {
            string const& new_target = target.substr(0, target.size()-1);
            auto f = umap.find({target, c});
            if(f != umap.end()) {
                auto ex_visited = f->second;
                for(auto ex_visited: ex_visited) {
                    bool valid = true;
                    for(auto& v: ex_visited) {
                        if(v.second && visited[v.first]) valid = false;
                    }
                    if(valid) { find = true; goto END;}
                }
            }
            if(!visited[c] && search(c, new_target)) {
                umap[{target, c}].push_back(visited);
                find = true;
                break;
            }
        }
        END:
        visited[root] = false;
        return find;
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