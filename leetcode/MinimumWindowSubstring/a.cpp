/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/838/

#include <cstdio>
#include <string>
#include <limits>
#include <unordered_set>
// 0    5    0
// ADOBECODEBANC
// l
//      r
class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    int ridx;  // result index
    int rlen = std::numeric_limits<int>::max();  // result length
    int l = 0, r = 0;
    std::unordered_multiset<int> ums(t.begin(), t.end());

    while (l <= r && r < s.size()) {
      printf("%2d %2d | ", l, r);
      for (int a : ums) {
        printf("%c ", a);
      }
      printf("\n");     
    
      if (ums.erase(s[r]) > 0) {
        if (ums.size() == 0 && (r - l + 1) < rlen) {
          ridx = l;
          rlen = r - l + 1;
          ums.insert(s[l++]);
          ++r;
        }
      } else {
        ++r;
      }
    }
    
    return s.substr(ridx, rlen);
  }
};

int main() {
  Solution s;
  printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
  
  return 0;
}
