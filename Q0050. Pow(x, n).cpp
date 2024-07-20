#include "utils/headers.h"

class Solution {
public:
    double myPow(double x, int n) {
        return solve(x, n);
    }

    double solve(double x, int n) {
        if(n == 0) return 1;
        if(n > 0) {
            double res = solve(x, n/2);
            return n%2 ? res*res*x : res*res;
        } else {
            double res = solve(x, n/2);
            return n%2==-1 ? res*res*1/x: res*res;
        }
    }
};

int main() {
    cout << Solution().myPow(2, -2) << endl;
}