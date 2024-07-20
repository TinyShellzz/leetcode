#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <set>
#include <unordered_set>
#include "utils/to_string.h"

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        multiset<vector<int>> points_sort_by_x;
        vector<int> res = vector<int>(queries.size(), 0);

        for(vector<int>& p: points) {
            points_sort_by_x.insert(p);
        }

        int x = 0, y = 1, r = 2;
        for(int i = 0; i < queries.size(); i++) {
            vector<int>& circle = queries[i];
            auto lower_bound_x = points_sort_by_x.lower_bound({circle[x]-circle[r], 0});
            auto upper_bound_x = points_sort_by_x.upper_bound({circle[x]+circle[r], 0});

            for(auto& it = lower_bound_x; it != (upper_bound_x == points_sort_by_x.end() ? upper_bound_x : ++upper_bound_x); it++) {
                vector<int> p = *it;
                int dis_2 = (p[0]-circle[0])*(p[0]-circle[0]) + (p[1]-circle[1])*(p[1]-circle[1]);
                if(dis_2 <= circle[r]*circle[r]) {  // in this circle
                    res[i]++;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution so;
    vector<vector<int>> points;
    vector<vector<int>> queries;

    cout << to_string(so.countPoints(points = {{1,3},{3,3},{5,3},{2,2}}, queries = {{2,3,1},{4,3,1},{1,1,2}})) << endl;
    cout << to_string(so.countPoints(points = {{1,1},{2,2},{3,3},{4,4},{5,5}}, queries = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}})) << endl;
}