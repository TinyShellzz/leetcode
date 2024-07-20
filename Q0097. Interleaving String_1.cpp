#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
struct my_hasher {
    size_t operator()(pair<int, int> const& p) const {
        hash<int> ha;
        return ha(p.first)^ha(p.second);
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int in1 = s1.size()-1, in3 = s3.size()-1;
        unordered_map<pair<int, int>, bool, my_hasher> mem;

        return solve(s1, s2, s3, in1, in3, mem);
    }

    bool solve(string&s1, string& s2, string &s3, int in1, int in3, unordered_map<pair<int, int>, bool, my_hasher> mem) {
        if(in3 == -1) return 1;
        auto f = mem.find({in1, in3});
        if(f != mem.end()) return f->second;

        int in2 = in3-in1-1;
        int ret1 = false, ret2 = false;
        if(in1 >= 0 && s1[in1] == s3[in3]) ret1 = solve(s1, s2, s3, in1-1, in3-1, mem);
        if(ret1) {
            mem[{in1, in3}] = true;
            return true;
        }
        if(in2 >= 0 && s2[in2] == s3[in3]) ret2 = solve(s1, s2, s3, in1, in3-1, mem);
        if(ret2) {
            mem[{in1, in3}] = true;
            return true;
        }

        mem[{in1, in3}] = false;
        return false;
    }
};

int main() {
    Solution so;

    cout << so.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}