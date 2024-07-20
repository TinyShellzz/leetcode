#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>
#include "utils/to_string.h"

struct my_hasher {
    size_t operator()(vector<int> const& v) const {
        hash<int> ha;
        size_t ret = 7;
        for(int a: v) ret ^= ha(a);
        return ret;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj = vector<vector<int>>(n+1, vector<int>());
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> c;
        vector<int> visited = vector<int>(n+1, 0);
        find_circle(adj, visited, c, 1, 0);

        unordered_set<vector<int>, my_hasher> uset = unordered_set<vector<int>, my_hasher>(c.begin(), c.end());
        for(int i = n-1; i >= 0; i--) {
            if(uset.find(edges[i]) != uset.end() || uset.find({edges[i][1], edges[i][0]}) != uset.end()) return edges[i];
        }
        return {};
    }

    bool find_circle(vector<vector<int>>& adj, vector<int>& visited, vector<vector<int>>& c, int i, int pre_i) {
        if(visited[i] == 1) {   // detected a circle
            return true;
        }

        visited[i] = 1;
        for(int j: adj[i]) {
            if(j == pre_i) continue;    // dont go back
            if(find_circle(adj, visited, c, j, i)) {
                if(c.empty()) c.push_back({i, j});
                else if(c.front()[1] != c.back()[0]) c.push_back({i, j});
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution so;
    vector<vector<int>> edges;

    cout << to_string(so.findRedundantConnection(edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}})) << endl; 
    cout << to_string(so.findRedundantConnection(edges = {{1,2}, {1,3}, {2,3}})) << endl;
    cout << to_string(so.findRedundantConnection(edges = {{9,10}, {5,8}, {2,6}, {1,5}, {3,8}, {4,9}, {8,10}, {4,10}, {6,8}, {7, 9}})) << endl;
}