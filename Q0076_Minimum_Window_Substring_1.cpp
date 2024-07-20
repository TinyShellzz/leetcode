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
  string minWindow(string s, string t) {
    if(s.size() < t.size()) return "";
    int L=0, R=0;
    int counts[52];
    memset(counts, 0, sizeof(counts));
    unordered_set<char> uset;
    
    for(char c: t) {
      uset.insert(c);
      counts[in(c)]--;
    }
    
    while(true) {
      counts[in(s[R])]++;
      if(counts[in(s[R])] == 0) uset.erase(uset.find(s[R]));
      if(!uset.size()) break;
      R++;
      if(R == s.size()) return "";
    }
    
    while(true) {
      if(counts[in(s[L])] - 1 < 0) break;
      counts[in(s[L])]--;
      L++;
    }
    int mn = R-L+1;
    string ans = s.substr(L, mn);
    
    while(true) {
      if(--counts[in(s[L])] == -1) uset.insert(s[L]);
      L++; R++;
      if(R == s.size()) break;
      if(++counts[in(s[R])] == 0) uset.erase(uset.find(s[R]));
      if(!uset.size()) {
        while(true) {
          if(counts[in(s[L])] - 1 < 0) break;
          counts[in(s[L])]--;
          L++;
        }
        if(mn > R-L+1) {
          mn = R-L+1;
          ans = s.substr(L, mn);
        }
      }
    }
    
    return ans;
  }
  
  int in(char c) {
    if(c <= 'Z') return c-'A';
    return c-'a'+26;
  }
};

int main() {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
}