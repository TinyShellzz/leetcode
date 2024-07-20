#include "utils/headers.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int limit = min((m+1)/2, (n+1)/2);

        vector<int> ans(m*n);
        int in = 0;
        for(int k = 0; k < limit; k++) {
            for(int i = k, j = k; j < n-k; j++) {
                ans[in++] = matrix[i][j];
            }

            for(int i = k+1, j = n-k-1; i < m-k; i++) {
                ans[in++] = matrix[i][j];
            }

            for(int i = m-k-1, j = n-k-2; j > k; j--) {
                ans[in++] = matrix[i][j];
            }

            for(int i = m-k-1, j = k; i > k; i--) {
                ans[in++] = matrix[i][j];
            }
        }

        if(min(m, n)%2) {
            if(m < n) {
                for(int i = limit, j = limit; j < n-limit; j++) ans[in++] = matrix[i][j];
            } else {
                for(int i = limit, j = limit; i < m-limit; i++) ans[in++] = matrix[i][j];
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    vector<vector<int>> matrix;

    cout << to_string(so.spiralOrder(matrix = {{2,5,8},{4,0,-1}})) << endl;
}