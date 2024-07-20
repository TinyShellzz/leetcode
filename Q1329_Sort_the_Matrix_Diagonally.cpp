#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> mat_dia;
        int height = mat.size();
        int width = mat[0].size();

        int in = 0;
        for(int h = height - 1; h >= 0; h--) {
            mat_dia.push_back(vector<int>());
            for(int w = 0, k = h; k < height && w < width; w++, k++) {
                mat_dia[in].push_back(mat[k][w]);
            }
            in++;
        }

        for(int i = 1; i < width; i++) {
            mat_dia.push_back(vector<int>());
            for(int j = 0, k = i; j < height && k < width; j++, k++) {
                mat_dia[in].push_back(mat[j][k]);
            }
            in++;
        }

        for(vector<int>& v: mat_dia) {
            sort(v.begin(), v.end());
        }

        in = 0;
        for(int h = height - 1; h >= 0; h--) {
            int l = 0;
            for(int w = 0, k = h; k < height && w < width; w++, k++) {
                mat[k][w] = mat_dia[in][l++];
            }
            in++;
        }

        for(int i = 1; i < width; i++) {
            int l = 0;
            for(int j = 0, k = i; j < height && k < width; j++, k++) {
                mat[j][k] = mat_dia[in][l++];
            }
            in++;
        }

        return mat;
    }
};

int main(){
    Solution so;
    vector<vector<int>> mat;

    so.diagonalSort(mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}});
    return 0;
}