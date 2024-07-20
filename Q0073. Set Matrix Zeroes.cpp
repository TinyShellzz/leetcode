#include "utils/headers.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool flag = false;  // flag for the first colum
        for(int i = 0, j = 0; i < m; i++) if(matrix[i][j] == 0) flag = true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }

        for(int j = 1; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }

        // genarate answer
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < m; i++) matrix[i][j] = 0;
            }
        }

        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; j++) matrix[i][j] = 0;
            }
        }

        if(flag) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution so;
    vector<vector<int>> matrix;

    so.setZeroes(matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}});
    cout << to_string(matrix) << endl;
}