#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size();
        int sum = 0;

        for(int i = 1; i <= len; i += 2) {
            for(int j = 0; i + j - 1 < len; j++) {
                for(int k = 0; k < i; k++) {
                    sum += arr[j+k];
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution so;
    vector<int> arr;

    so.sumOddLengthSubarrays(arr = {1,4,2,5,3});
}