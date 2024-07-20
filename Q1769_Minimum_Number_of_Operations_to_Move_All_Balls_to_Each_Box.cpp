#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/to_string.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res = vector<int>(boxes.size(), 0);

        int total = boxes[0] - '0';  // total ball amount
        for(int i = 1; i < boxes.size(); i++) {
            res[0] += i*(boxes[i] - '0');     // first result
            total += boxes[i] - '0';
        }

        int balls = boxes[0] - '0';  // balls amount from box 0-i
        for(int i = 1; i < boxes.size(); i++) {
            res[i] = res[i-1] + balls - (total - balls);
            balls += boxes[i] - '0';
        }

        return res;
    }
};

int main(){
    Solution so;

    cout << to_string(so.minOperations("110")) << endl;
    cout << to_string(so.minOperations("001011")) << endl;
}