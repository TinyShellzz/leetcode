#include "utils/headers.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int i = 0;
        int j = i+1;
        int ans = 0;
        while(j < intervals.size()) {
            while(j < intervals.size() && intervals[j][0] < intervals[i][1]) {
                ans++;
                if(intervals[i][1] > intervals[j][1]) i = j;
                j++;
            }
            i = j;
            j = i+1;
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<vector<int>> intervals;

    cout << so.eraseOverlapIntervals(intervals = {{1,2}, {2,3}, {3,4}, {1,3}}) << endl;
}