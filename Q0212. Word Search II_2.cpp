#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(string& str: words) {
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {
                    if(search(board, i, j, str, 0)) {
                        ans.push_back(str);
                        goto NEXT;
                    }
                }
            }
            NEXT:;
        }

        return ans;
    }


    bool search(vector<vector<char>>& board, int i, int j, string const& target, int in) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if(in == target.size()) return false;
        if(board[i][j] != target[in]) return false;
        if(in == target.size() - 1) return true;

        vector<vector<char>> copy = board;
        copy[i][j] = 0;     // i, j is visited
        in++;

        return search(copy, i-1, j, target, in) || search(copy, i+1, j, target, in) || search(copy, i, j-1, target, in) || search(copy, i, j+1, target, in);
    }
};

int main() {
    Solution so;
    vector<vector<char>> board;
    vector<string> words;

    cout << to_string(so.findWords(board = {{'a', 'a'}}, words = {"aaa"})) << endl;
    cout << to_string(so.findWords(board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}}, words = {"oath","pea","eat","rain"})) << endl;
}