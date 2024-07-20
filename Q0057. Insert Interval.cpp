#include "utils/headers.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto low = lower_bound(intervals.begin(), intervals.end(), newInterval);
        if(low == intervals.end()) {
            if(intervals.size() == 0 || intervals.back().at(1) < newInterval[0]) intervals.push_back(newInterval);
            else intervals.back()[1] = max(intervals.back().at(1), newInterval[1]);
            return intervals;
        }

        int a = newInterval[0];
        int b = newInterval[1];
        vector<vector<int>>::iterator start;
        int start_val;
        if(low != intervals.begin()) {
            auto low_1 = low - 1;
            vector<int>& first = *low_1;
            vector<int>& second = *low;

            if(a <= first[1]) {
                start = low_1;
                start_val = first[0];
            }
            else {
                start = low;
                start_val = a;
            }
        } else {
            start = low;
            start_val = min(low->at(0), newInterval[0]);
        }

        vector<vector<int>>::iterator end;
        int end_val;
        auto it = start;
        for(; it != intervals.end(); it++) {
            if(b < it->at(0)) {
                end = it;
                end_val = b;
                break;
            } else if(b <= it->at(1)) {
                end = it+1;
                end_val = it->at(1);
                break;
            }
        }
        if(it == intervals.end()) {
            end = intervals.end();
            end_val = b;
        }

        vector<vector<int>> ans(intervals.begin(), start);
        ans.push_back({start_val, end_val});
        for(auto it = end; it != intervals.end(); it++) ans.push_back(*it);

        return ans;
    }
};

int main() {
    Solution so;
    vector<vector<int>> intervals;
    vector<int> newInterval;

    auto res1 = so.insert(intervals = {{1,5}}, newInterval = {2,3});
    for(auto e: res1) cout << to_string(e);
    cout << endl;
}