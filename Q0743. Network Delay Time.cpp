#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

struct cmp_less {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) const {
        return a.first > b.first;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto e: times) {
            adj[e[0]].push_back({e[2], e[1]});
            auto f = adj.find(e[1]);
            if(f == adj.end()) adj[e[1]];
        }

        // using bfs
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_less> pq;
        pq.push({0, k});
        unordered_set<int> visited;
        int ans;
        while(n != 0 && pq.size() && visited.size() != adj.size()) {
            while(visited.find(pq.top().second) != visited.end()) pq.pop();
            pair<int, int> top = pq.top();
            pq.pop();
            n--;
            ans = top.first;
            visited.insert(top.second);
            for(pair<int, int> const& n: adj[top.second]) {
                if(visited.find(n.second) == visited.end()) {
                    pq.push({top.first+n.first, n.second});
                }
            }
        }


        return n == 0 ? ans : -1;
    }
};

int main() {
    Solution so;
    vector<vector<int>> times;

    cout << so.networkDelayTime(times = {{2,1,1}, {2,3,1}, {3,4,1}}, 4, 2) << endl;
}