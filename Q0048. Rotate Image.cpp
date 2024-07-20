#include "utils/headers.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k = n/2;

        for(int i = 0; i < k; i++) {
            for(int j = i; j < n-i-1; j++) {
                int& point1 =  matrix[i][j];
                int& point2 = matrix[j][n-i-1];
                int& point3 = matrix[n-i-1][n-j-1];
                int& point4 = matrix[n-j-1][i];
                int temp2 = point2;
                point2 = point1;
                int temp3 = point3;
                point3 = temp2;
                int temp4 = point4;
                point4 = temp3;
                point1 = temp4;
            }
        }
    }
};

int main() {
    Solution so;
    vector<vector<int>> matrix;

    so.rotate(matrix = {{1,2,3}, {4,5,6}, {7,8,9}});
}