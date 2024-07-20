#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>
#include "utils/to_string.h"


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent = vector<int>(n+1, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        vector<int> rank = vector<int>(n+1, 1);
        for(auto e: edges) if(!union_area(rank, parent, e[0], e[1])) return e;

        return {};
    }

    // find parent of n
    int find(vector<int>& par, int n) {
        int p = par[n];

        while(p != par[p]) {
            par[p] = par[par[p]];   // this loop will be faster next time
            p = par[p];
        }

        return p;
    }

    // union two connected area, connected by edge(n1, n2)
    bool union_area(vector<int>& rank, vector<int>& par, int n1, int n2) {
        int p1 = find(par, n1);
        int p2 = find(par, n2);

        if(p1 == p2) return false;      // two area is already connected
        if(rank[p1] >= rank[p2]) {      // smaller area union to the larger one
            par[p2] = p1;
            rank[p1] += p2;
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

int main() {
    Solution so;
    vector<vector<int>> edges;

    cout << to_string(so.findRedundantConnection(edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}})) << endl; 
    cout << to_string(so.findRedundantConnection(edges = {{1,2}, {1,3}, {2,3}})) << endl;
    cout << to_string(so.findRedundantConnection(edges = {{9,10}, {5,8}, {2,6}, {1,5}, {3,8}, {4,9}, {8,10}, {4,10}, {6,8}, {7, 9}})) << endl;
}