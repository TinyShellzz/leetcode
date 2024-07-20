#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <queue>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> stack;
        vector<int> areas = vector<int>(len, 0);

        for(int i = 0; i < len; i++) {
            while(!stack.empty() && heights[stack.back()] > heights[i]) {
                int j = stack.back();
                areas[j] = heights[j]*(i-j);
                stack.pop_back();
            }

            stack.push_back(i);
        }

        while(!stack.empty()) {
            int j = stack.back();
            areas[j] = heights[j]*(len-j);
            stack.pop_back();
        }

        for(int i = len-1; i >=0 ; i--) {
            while(!stack.empty() && heights[stack.back()] > heights[i]) {
                int j = stack.back();
                areas[j] += heights[j]*(j-i-1);
                stack.pop_back();
            }

            stack.push_back(i);
        }

        while(!stack.empty()) {
            int j = stack.back();
            areas[j] += heights[j]*j;
            stack.pop_back();
        }

        int mx = 0;
        for(int a: areas) {
            if(mx < a) mx = a;
        }

        return mx;
    }
};

int main() {
    Solution so;
    vector<int> heights;

    cout << so.largestRectangleArea(heights = {2,1,5,6,2,3}) << endl;
}