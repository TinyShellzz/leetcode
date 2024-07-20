#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char cs[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        char w[10];
        int len = 0;
        while(num) {
            w[len++] = num%10;
            num /= 10;
        }

        string res = "";
        for(int i = len - 1; i >= 0; i--) {
            if(w[i] < 4) {res.append(w[i], cs[2*i]);}
            else if(w[i] == 4) {res.push_back(cs[2*i]); res.push_back(cs[2*i+1]);}
            else if(w[i] == 5) {res.push_back(cs[2*i+1]);}
            else if(w[i] < 9) {res.push_back(cs[2*i+1]); res.append(w[i]-5, cs[2*i]);}
            else if(w[i] == 9) {res.push_back(cs[2*i]); res.push_back(cs[2*i+2]);}
        }

        return res;
    }
};

int main(){
    Solution so = Solution();
    cout << so.intToRoman(3) << endl;
    cout << so.intToRoman(58) << endl;
    cout << so.intToRoman(1994) << endl;
    cout << so.intToRoman(3999) << endl;
    cout << so.intToRoman(1) << endl;
}