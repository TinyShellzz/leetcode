#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        int begin = -1, end = -1;
        unordered_map<string, int> umap;
        for(int i = 0; i < len; i++) {
            umap[wordList[i]] = i;
        }
        auto f1 = umap.find(endWord);
        if(f1 != umap.end()) end = f1->second;
        else return 0;
        auto f2 = umap.find(beginWord);
        if(f2 == umap.end()) {
            len++;
            begin = len-1;
            wordList.push_back(beginWord);
            umap[beginWord] = begin;
        } else begin = f2->second;

        vector<vector<int>> adj;
        for(string w: wordList) {
            adj.push_back(adjacent(umap, w));
        }
        vector<bool> visited = vector<bool>(len, false);

        vector<vector<int>> *v1, *v2;
        v1 = new vector<vector<int>>();
        v2 = new vector<vector<int>>();
        v1->push_back({-1, begin});
        int dis = 0;
        bool find = false;
        while(!v1->empty()) {
            while(!v1->empty()) {
                auto cur = v1->back();
                visited[cur[1]] = true;
                if(cur[1] == end) {
                    find = true;
                    goto END;
                }
                v1->pop_back();

                for(int j: adj[cur[1]]) {
                    if(j == cur[0]) continue;   // do not go back
                    if(!visited[j]) v2->push_back({cur[1], j});
                }
            }

            dis++;
            auto tmp = v1;
            v1 = v2;
            v2 = tmp;
            v2->clear();
        }
        END:

        return find ? dis+1 : 0;
    }

    vector<int> adjacent(unordered_map<string, int>& umap, string str) {
        vector<int> ret;
        for(int i = 0; i < str.size(); i++) {
            char tmp = str[i];
            for(char j = 'a'; j <= 'z'; j++) {
                if(j == tmp) continue;
                str[i] = j;
                auto f = umap.find(str);
                if(f != umap.end()) ret.push_back(f->second);
            }
            str[i] = tmp;
        }

        return ret;
    }
};

int main() {
    Solution so;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << so.ladderLength("hit", "cog", wordList) << endl;
}