#include "utils/headers.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx = INT32_MIN;
        int len = fruits.size();
        unordered_map<int, int> umap;
        int left = 0, right = 0;
        while(true) {
            if(umap.size() <= 2) {
                while(right < len) {
                    if(umap.size() == 2 && umap.find(fruits[right]) == umap.end()) break;
                    umap[fruits[right++]]++;
                }
                mx = max(mx, right-left);
            }
            if(right == len) break;
            
            auto f = umap.find(fruits[left]);
            f->second--;
            if(f->second == 0) umap.erase(f);
            umap[fruits[right]]++;
            left++; right++;
        }

        return mx;
    }
};
int main() {
    Solution so;
    vector<int> fruits;

    cout << so.totalFruit(fruits = {3,3,3,1,2,1,1,2,3,3,4}) << endl;
}