#include "utils/headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left, right;
        left = 0;
        int ans = 0;
        while(true) {
            while(left+1 < prices.size() && prices[left] > prices[left+1]) left++;
            if(left+1 == prices.size()) break;
            right = left;
            while(right+1 < prices.size() && prices[right] < prices[right+1]) right++;
            ans += prices[right]-prices[left];
            left = right;
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<int> prices;

    cout << so.maxProfit(prices = {7,1,5,3,6,4}) << endl;
}