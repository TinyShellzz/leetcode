#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>
#include "utils/to_string.h"

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bool set_A[51];
        memset(set_A, 0, sizeof(set_A));
        unordered_set<int> set_B;

        int n = A.size();
        vector<int> C = vector<int>(n, 0);
        int common = 0;
        for(int i = 0; i < n; i++) {
            set_A[A[i]] = 1;
            set_B.insert(B[i]);

            vector<unordered_set<int>::iterator> erases;
            for(auto it = set_B.begin(); it != set_B.end(); it++) {
                if(set_A[*it]) {
                    common++;
                    erases.push_back(it);
                }
            }
            for(auto e: erases) set_B.erase(e);

            C[i] = common;
        }

        return C;
    }
};

int main() {
    Solution so;
    vector<int> A, B;

    cout << to_string(so.findThePrefixCommonArray(A= {1,3,2,4}, B = {3,1,2,4})) << endl;
}