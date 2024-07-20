#include "utils/headers.h"

struct cmp_less {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_less> pq;
        unordered_map<int, int> umap;
        vector<int> ans = queries;

        sort(intervals.begin(), intervals.end());
        sort(queries.begin(), queries.end());

        int i = 0;
        for(int q: queries) {
            for(; i < intervals.size() && intervals[i][0] <= q; i++) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                
            }

            while(pq.size() && pq.top().second < q) pq.pop();
            umap[q] = pq.empty() ? -1 : pq.top().first;
        }

        for(int& a: ans) a = umap[a];

        return ans;
    }
};

int main() {
    Solution so;
    vector<vector<int>> intervals;
    vector<int> queries;

    cout << to_string(so.minInterval(intervals = {{1,4}, {2,4}, {3,6}, {4,4}}, queries = {2,3,4,5})) << endl;
}