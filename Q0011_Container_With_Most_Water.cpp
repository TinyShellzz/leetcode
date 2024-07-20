#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>


/**
 * 从最宽的部分开始, L=0, R=len-1分别为左右边界
 * 每次只移动高度小的边界, 相同时比较 height[L+1] 和 height[R-1]
 * 上面这些操作, 可以保证在当前宽度下, 选到最高的两个(当前宽度最大面积)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int L = 0, R = len - 1;     //left and right border

        int mx = -1;        // max area
        while(L < R) {
            int w = R - L;      // weight
            if(height[L] < height[R]) {
                mx = max(w*height[L], mx);
                L++;
            } else if(height[L] > height[R]) {
                mx = max(w*height[R], mx);
                R--;
            } else {
                mx = max(w*height[R], mx);
                height[L+1] < height[R-1] ? L++ : R--;
            }
        }

        return mx;
    }
};

int main(){
    Solution s = Solution();
    vector<int> l1 = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(l1) << endl;
    vector<int> l2 = {1, 1};
    cout << s.maxArea(l2) << endl;
}