#include "utils/headers.h"

class NumMatrix {
    vector<vector<int>> prefix;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefix = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; row2++; col1++; col2++;
        return prefix[row2][col2]-prefix[row1-1][col2]-prefix[row2][col1-1]+prefix[row1-1][col1-1];
    }
};

int main() {
    vector<vector<int>> matrix;
NumMatrix numMatrix = NumMatrix(matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}});
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
}