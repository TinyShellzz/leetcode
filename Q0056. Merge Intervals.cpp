#include "utils/headers.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size();) {
            expand(intervals, i, ans);
        }

        return ans;
    }

    void expand(vector<vector<int>>& intervals, int& i, vector<vector<int>>& ans) {
        int start_val = intervals[i][0];
        int b = intervals[i][1];
        int end_val = b;
        i++;
        int j;

        while(j != i) {
            j = i;
            for(; i < intervals.size(); i++) {
                if(end_val < intervals[i][0]) {
                    break;
                } else if(end_val <= intervals[i][1]) {
                    end_val = intervals[i][1];
                    i++;
                    break;
                }
            }
        }

        ans.push_back({start_val, end_val});
    }
};