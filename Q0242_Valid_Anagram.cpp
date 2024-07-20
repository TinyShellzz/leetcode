#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int counts[26];     // counts of charactor range from 'a' to 'z'
        memset(counts, 0, sizeof(counts));

        // count charactor in s
        for(char c: s) {
            counts[c - 'a']++;
        }

        // then count charactor in t
        for(char c: t) {
            counts[c - 'a']--;
        }

        // check counts
        for(int i: counts) {
            if(i != 0) return false;
        }

        return true;
    }
};