#include "utils/headers.h"

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> umap;
        for(auto rec: rectangles) {
            umap[(double)rec[1]/rec[0]]++;
        }

        long long ans = 0;
        for(auto& p: umap) {
            ans += combination(p.second, 2);
        }

        return ans;
    }

    long long combination(int m, int n) {
        if(n == 0 || m == n) return 1;
        long long ret = 1;
        for(int i = 1; i <= n; i++) {
            ret *= m--;
            ret /= i;
        }

        return ret;
    }
};

int main() {
    Solution so;
    vector<vector<int>> rectangles;

    cout << so.interchangeableRectangles(rectangles = {{4,8},{3,6},{10,20},{15,30}}) << endl;
}