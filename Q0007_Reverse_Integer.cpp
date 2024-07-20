#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == INT32_MIN) return 0;

        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }
        if(x < 10) return sign*x;

        int nums[10];
        int i = 0;
        while(x != 0) {
            nums[i++] = x%10;
            x /= 10;
        }


        unsigned int res = 0;
        unsigned int j = 1;
        bool exceeded = false;
        for(i--; i >= 0; i--) {
            if(j == 1000000000 && nums[i] > 2) {
                exceeded = true;
                break;
            }
            res += j*nums[i];
            if(res > INT32_MAX) {
                exceeded = true;
                break;
            }
            j *= 10;
        }

        if(exceeded) return 0;
        return res*sign;
    }
};

int main(){
    Solution s = Solution();
    cout << s.reverse(1534236469);
}