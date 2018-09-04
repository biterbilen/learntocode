/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/838/

#include <cstdio>
#include <string>
#include <limits>
#include <unordered_set>

// 
// 
// 0    5    0
// ADOBECODEBANC
//          l
//             r
class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    if (s.empty() || t.empty())
      return "";

    int ridx = -1;  // result index
    int rlen = std::numeric_limits<int>::max();  // result length
    int l = 0, r = 0;  // left, right
    std::unordered_multiset<int> umso(t.begin(), t.end());
    std::unordered_multiset<int> umsb(t.begin(), t.end());

    // forward left
    while (umso.find(s[l]) == umso.end())
      r = ++l;

    while (l <= r && r <= s.size() && l <= s.size() - t.size()) {
      printf("%2d %2d | ", l, r);
      for (int a : umsb) {
        printf("%c ", a);
      }
      printf("\n");
      
      if (r == s.size() - 1) {
        while (umsb.size() > 0 && l <= r && l <= s.size() - t.size()) {
          if (umsb.erase(s[l]) == 0)
            ++l;
        }
      } else {
        umsb.erase(s[r]);
      }

      if (umsb.size() == 0) {
        if ((r - l + 1) < rlen) {
          ridx = l;
          rlen =  r - l + 1;
        }
        umsb.insert(s[l++]);
        while (umso.find(s[l]) == umso.end())
          ++l;
        ++r;
      } else {
        ++r;
      }
    }
    if (ridx < 0)
      return "";

    return s.substr(ridx, rlen);
  }
};

int main() {
  Solution s;
  // printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
  // printf("%s\n", s.minWindow("a", "ab").c_str());
  printf("%s\n", s.minWindow("a", "aa").c_str());
  return 0;
}
