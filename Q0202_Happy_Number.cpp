#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        vector<int> digits;
        unordered_set<int> set;
        set.insert(n);

        while(n != 1) {
            int *digits = getDigits(n);

            n = 0;
            for(int i = 0; digits[i] != -1; i++) {
                n += digits[i]*digits[i];
            }
            free(digits);

            if(set.find(n) != set.end()) return false;
            else set.insert(n);
        }

        return true;
    }

    int *getDigits(int n){
        int *digits = (int *)malloc(12*sizeof(int));
        memset(digits, -1, 12*sizeof(int));

        int i = 0;
        while(n) {
            digits[i++] = n%10;
            n /= 10;
        }

        return digits;
    }
};

int main(){
    Solution so;

    cout << so.isHappy(19) << endl;
    cout << so.isHappy(2) << endl;
}