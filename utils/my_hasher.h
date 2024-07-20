#pragma once
#include <vector>
using namespace std;

struct  my_hasher {
  size_t operator()(vector<int> const& vec) const {
    size_t ret = 0;
    for(auto& i : vec) {
      ret ^= hash<int>()(i);
    }
    return ret;
  }
}; 