#include "utils/headers.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int left, right;
        left = right = 0;

        int sum = 0;
        while(true) {
            sum += gas[right%len] - cost[right%len];
            right++;
            if(sum < 0) {
                sum = 0;
                left = right;
                if(left >= len) return -1;
            } else {
                if(left == right%len) break;
            }
        }

        return left;
    }
};

int main() {
    Solution so;
    vector<int> gas, cost;

    cout << so.canCompleteCircuit(gas = {1,2,3,4,3,2,4,1,5,3,2,4}, cost = {1,1,1,3,2,4,3,6,7,4,3,1}) << endl;
}